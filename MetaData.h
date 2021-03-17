#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

struct meta_head
{
private:
	unsigned int num_level;
	std::string name;
	unsigned short int status;
	std::string name_method;

public:
	friend std::ostream& operator<<(std::ostream& out, const meta_head& head);
	friend std::istream& operator>> (std::istream& in, meta_head& point);
};

inline std::ostream& operator<< (std::ostream& out, const meta_head& head)
{
	if (head.status != 2)
	{
		for (auto i = 0; i < head.num_level; ++i)
			out << "\t";
		out << head.name << " " <<	head.name_method;
		if (head.status == 1)
			std::cout << " (Недоступно)";
		out << std::endl;
	}
	return out;
}

inline std::istream& operator>> (std::istream& in, meta_head& head)
{
	std::string buffer_array[4];
	
	for (auto& buffer : buffer_array)
		in >> buffer;

	head.num_level = std::stoi(buffer_array[0]);
	head.name = buffer_array[1];
	head.status = std::stoi(buffer_array[2]);
	head.name_method = buffer_array[3];

	return in;
}

class meta_data
{
private:
	std::vector<meta_head> vector_meta_heads_;
	const std::string file_name_;
	void add_head(const std::string& buffer);

public:
	meta_data(const std::string& file_name);
	void read_heads_file();
	void print_head();
};