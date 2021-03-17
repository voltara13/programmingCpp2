#include <iostream>

#include "MetaData.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	meta_data meta_data("data.txt");
	meta_data.read_heads_file();
	meta_data.print_head();
}
