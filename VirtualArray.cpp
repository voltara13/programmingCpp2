#include "VirtualArray.h"

#include <fstream>
#include <iostream>
#define SIZE_INT sizeof(int)

VirtualArray::VirtualArray(const long int size, const char* file)
{
	std::ofstream virtue_file(file, std::ofstream::binary);
	virtue_file.write("VM" , 2);
	const auto size_page = 512.0 / SIZE_INT / 8 + 512.0;
	for(auto size_file = ceil(size * static_cast<double>(SIZE_INT) / size_page) * size_page; size_file; size_file -= 1)
		virtue_file.write("0", 1);
	virtue_file.close();
}

int* VirtualArray::calc_address(const int index)
{
	return nullptr;
}

void VirtualArray::read_var(const int index, const int* var)
{
	
}

void VirtualArray::write_var(const int index, const int* var)
{
	
}

//int& VirtualArray::operator[] (const int index) const
//{
//	return {NULL};
//}
