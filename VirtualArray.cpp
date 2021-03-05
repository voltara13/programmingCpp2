#include "VirtualArray.h"\


#include <iostream>
constexpr int size_int = sizeof(int);
constexpr int count_int_page = 512.0 / size_int;
constexpr int size_page = count_int_page + 512.0;

VirtualArray* VirtualArray::virtual_array_ = nullptr;

bool VirtualArray::page::modified;
int VirtualArray::page::num_page_in_mem;
int VirtualArray::page::array[512 / sizeof(int)];
bool VirtualArray::page::bit_map[512 / sizeof(int)];

VirtualArray* VirtualArray::GetInstance(const long int& size, const char* file_name)
{
	if (virtual_array_ == nullptr)
		virtual_array_ = new VirtualArray(size, file_name);
	return virtual_array_;
}

VirtualArray::VirtualArray(const long int& size, const char* file_name)
{
	file.open(file_name, std::fstream::in | std::fstream::out | std::fstream::binary | std::fstream::trunc);
	file.write("VM" , 2);
	count_page = ceil(size / count_int_page);
	if (!count_page) count_page = 1;
	for (long long int size_file = count_page * size_page; size_file; --size_file)
		file.write("\0", 1);
}

VirtualArray::~VirtualArray()
{
	save_page();
	file.close();
}


int VirtualArray::calc_address(const int& index)
{
	try
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
	catch (_exception)
	{
		return NULL;
	}

}

void VirtualArray::save_page()
{
	if (page::modified)
	{
		const int byte_page = size_page * page::num_page_in_mem + 2;
		write_page(byte_page);
	}
}

void VirtualArray::read_page(const int& page_num)
{
	page::num_page_in_mem = page_num;
	page::modified = false;
	const int byte_page = size_page * page_num + 2;
	file.seekg(byte_page);
	file.read(reinterpret_cast<char*>(&page::bit_map), count_int_page);
	file.read(reinterpret_cast<char*>(&page::array), size_int * count_int_page);
}

void VirtualArray::write_page(const int& byte_page)
{
	file.seekp(byte_page);
	file.write(reinterpret_cast<char*>(&page::bit_map), count_int_page);
	file.write(reinterpret_cast<char*>(&page::array), size_int * count_int_page);
}

int VirtualArray::read_var(const int& index)
{
	const int index_array = calc_address(index);
	if (!page::bit_map[index_array])
		throw "ѕо данному индексу значение отсутствует";
	return page::array[index_array];
}

void VirtualArray::write_var(const int& index, const int& value)
{
	const int index_array = calc_address(index);
	page::array[index_array] = value;
	page::bit_map[index_array] = true;
	page::modified = true;
}