#include <iostream>
#include <map>
#include "HashTable.h"

struct personStruct
{
	std::string name = "";
	std::string surname = "";
	std::string fatherName = "";
	std::string company = "";
	std::string rank = "";
	std::string mail = "";
};

int main()
{
	HashTable<std::string> ht;
	//personStruct.name = "";
	std::map<int, int> tmpMap;
	std::pair <std::string, std::string> data1;
	data1 = std::make_pair("4358969", "Filin Artem");
	ht.add(data1);
	data1 = std::make_pair("234", "Pestov loh");
	ht.add(data1);
	//ht.print();
	std::cout << ht["Pestov loh"] << std::endl;
	std::cout << ht["Bbbbbbb"] << std::endl;
	//ht.erase("Pestov loh");
	std::cout << ht["Pestov loh"] << std::endl;
	ht.print();
	auto iter = ht.find("Pestov loh");
	std::cout << iter->first << std::endl;
	system("pause");
	return 0;
}