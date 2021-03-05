#include <iostream>

#include "VirtualArray.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	const int n = 1000;
	VirtualArray* a = VirtualArray::GetInstance(n);
	for (int i = 0; i < n; i++)
		a->write_var(i, i);
	for (int i = 0; i < n; i++)
		std::cout << a->read_var(i) << std::endl;
	delete a;
	return 0;
}
