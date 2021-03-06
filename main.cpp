#include <iostream>

#include "VirtualArray.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	int size = 30 + rand() % 1000;
	int index[30];
	VirtualArray* a = VirtualArray::GetInstance(size); //������ ������ (������������ ������� "��������")

	std::cout << "������: " << size << std::endl;
	
	std::cout << "���������� ��������\n";
	for (int& i : index) //���������� �����
	{
		i = 0 + rand() % size;
		int value = 0 + rand() % 1000;
		a->write_var(i, value);
		std::cout << "[" << i  << "]: "<< value << std::endl;
	}
	
	std::cout << "��������� ��������\n";
	for (int& i : index) //��������� �����
		std::cout << "[" << i << "]: " << a->read_var(i) << std::endl;
	
	delete a;
	return 0;
}
