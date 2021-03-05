#pragma once
#include <fstream>

class VirtualArray
{
private:
	struct page
	{
		static bool modified;
		static int num_page_in_mem;
		static int array[512 / sizeof(int)];
		static bool bit_map[512 / sizeof(int)];
	};
	VirtualArray(const long int& size, const char* file_name = "virtualMem.bin");
	static VirtualArray* virtual_array_;
	int calc_address(const int& index);
	void read_page(const int& page_num);
	void write_page(const int& byte_page);
	void save_page();
	std::fstream file;
	int count_page;
public:
	~VirtualArray();
	VirtualArray(VirtualArray& other) = delete;
	void operator= (const VirtualArray&) = delete;
	static VirtualArray* GetInstance(const long int& size, const char* file_name = "virtualMem.bin");
	int read_var(const int& index);
	void write_var(const int& index, const int& value);
};
