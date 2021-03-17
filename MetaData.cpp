#include "MetaData.h"

meta_data::meta_data(const std::string& file_name) : file_name_(file_name) {}

void meta_data::add_head(const std::string& buffer)
{
	std::stringstream buffer_stream;
	meta_head head;
	buffer_stream.str(buffer);
	
	buffer_stream >> head;

	vector_meta_heads_.emplace_back(head);
}

void meta_data::read_heads_file()
{
	std::string buffer;
	std::ifstream file(file_name_);

	while (std::getline(file, buffer))
		add_head(buffer);

	file.close();
}

void meta_data::print_head()
{	
	for (auto& head : vector_meta_heads_)
		std::cout << head;	
}


