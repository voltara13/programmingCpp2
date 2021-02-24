#pragma once

class VirtualArray
{
public:
	VirtualArray(long int size, const char* file = "virtualMem.bin");
	static int* calc_address(int index);
	static void read_var(int index, const int* var);
	static void write_var(int index, const int* var);
	int& operator[] (int index) const;
	
	struct page
	{
		bool status = false;
		int numPage;
		int time;
		int array[512 / sizeof(int)];
	};
};