#include "VirtualArray.h"

constexpr int size_int = sizeof(int);
constexpr int count_int_page = 512 / size_int;
constexpr int size_page = 512 + (count_int_page / CHAR_BIT);

VirtualArray* VirtualArray::virtual_array_ = nullptr;

bool VirtualArray::page::modified;
int VirtualArray::page::num_page_in_mem;
int VirtualArray::page::array[512 / sizeof(int)];
std::bitset<512 / sizeof(int)> VirtualArray::page::bit_map;

VirtualArray* VirtualArray::GetInstance(const long long int& size, const char* file_name)
{
	if (virtual_array_ == nullptr)
		virtual_array_ = new VirtualArray(size, file_name);
	return virtual_array_;
}

VirtualArray::VirtualArray(const long long int& size, const char* file_name) : size_array(size)
{
	file.open(file_name, std::fstream::in | std::fstream::out | std::fstream::binary | std::fstream::trunc);
	file.write("VM" , 2);
	//Округляя в большую сторону, вычисляем необходимое количество страниц и умножаем на размер страницы
	for (unsigned long long int size_file = ceil(static_cast<double>(size) / static_cast<double>(count_int_page)) * size_page; size_file; --size_file)
		file.write("\0", 1); //Заполняем файл нулевыми байтами
}

VirtualArray::~VirtualArray() //Перед удалением объекта происходит сохранение и закрытие файла
{
	save_page();
	file.close();
}


int VirtualArray::calc_address(const long long int& index)
{
	const int page_num = index / count_int_page;
	if (page_num != page::num_page_in_mem)
	{
		save_page();
		read_page(page_num);
	}
	const int index_array = index - page_num * count_int_page;
	return index_array;
}

void VirtualArray::save_page()
{
	if (page::modified) //Сохранение происходит только в том случае, если страница модифицировалась
		write_page();
}

void VirtualArray::read_page(const long long int& page_num)
{
	page::num_page_in_mem = page_num;
	page::modified = false;
	const int byte_page = size_page * page_num + 2; //Вычисляется первый байт нужной страницы
	try
	{
		file.seekg(byte_page);
		file.read(reinterpret_cast<char*>(&page::bit_map), count_int_page / CHAR_BIT);
		file.read(reinterpret_cast<char*>(&page::array), size_int * count_int_page);
	}
	catch (const std::exception&)
	{
		std::cerr << "\nПроизошла ошибка при чтении файла\n";
		exit(1);
	}
}

void VirtualArray::write_page()
{
	const int byte_page = size_page * page::num_page_in_mem + 2; //Вычисляется первый байт нужной страницы
	try
	{
		file.seekp(byte_page);
		file.write(reinterpret_cast<char*>(&page::bit_map), count_int_page / CHAR_BIT);
		file.write(reinterpret_cast<char*>(&page::array), size_int * count_int_page);
	}
	catch (const std::exception&)
	{
		std::cerr << "\nПроизошла ошибка при записи в файл\n";
		exit(1);
	}
}

int VirtualArray::read_var(const long long int& index)
{
	if (index >= 0 && index < size_array)
	{
		const int index_array = calc_address(index);
		if (page::bit_map[index_array])
			return page::array[index_array];
		std::cerr << "\nПо данному индексу значений не найдено\n";
		exit(2);
	}
	std::cerr << "\nИндекс за пределами массива\n";
	exit(2);
}

void VirtualArray::write_var(const long long int& index, const int& value)
{
	if (!(index >= 0 && index < size_array))
	{
		std::cerr << "\nИндекс за пределами массива\n";
		exit(2);
	}
	const int index_array = calc_address(index);
	page::array[index_array] = value;
	page::bit_map[index_array] = true;
	page::modified = true;
}