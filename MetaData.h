#pragma once
#include <string>

struct meta_head
{
	unsigned int num_level;
	unsigned short int status;
	std::string name;
	std::string name_method;
};

class MetaData
{
	meta_head* array[];
	
};
