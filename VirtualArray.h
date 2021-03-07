#pragma once
#include <iostream>
#include <bitset>
#include <fstream>

class VirtualArray
{
private:
	std::fstream file;
	const long long int size_array;
	
	struct page
	{
		static bool modified;
		static int num_page_in_mem;
		static int array[512 / sizeof(int)];
		static std::bitset<512 / sizeof(int)> bit_map;
	};
	
	VirtualArray(const long long int& size, const char* file_name = "virtualMem.bin");
	static VirtualArray* virtual_array_;
	int calc_address(const long long int& index);
	void read_page(const long long int& page_num);
	void write_page();
	void save_page();
	
public:
	~VirtualArray();
	static VirtualArray* GetInstance(const long long int& size, const char* file_name = "virtualMem.bin");
	int read_var(const long long int& index);
	void write_var(const long long int& index, const int& value);

	VirtualArray(VirtualArray& other) = delete;
	void operator= (const VirtualArray&) = delete;
};
