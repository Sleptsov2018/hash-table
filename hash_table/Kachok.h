#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>

template<typename T, typename R>
struct info
{
	T userName;
	R userNumber;
};

template<typename T, typename R>
struct record
{
	int key;
	std::list<info<T, R> > values;
};

template<typename T, typename K>
class hashtable
{
private:
	std::vector<record<T, K> > _table;
public:
	hashtable()
	{
		_table.resize(10);
	}
	int hashing(std::string data)
	{
		return data.size() % 10;
	}
	hashtable& add(struct info<T, K>& data)
	{
		int hKey;
		hKey = hashing(data.userName);
		_table[hKey].values.push_back(data);
		_table[hKey].key = hKey;
		return *this;
	}

	void print()
	{
		typename std::vector<record<T, K> >::iterator it;
		for (it = _table.begin(); it != _table.end(); it++)
		{
			std::cout << it->key << ' ';
			for (auto it1 = it->values.begin(); it1 != it->values.end(); it1++)
			{
				std::cout << it1->userName << ' ' << it1->userNumber;
			}
			std::cout << std::endl;
		}
	}

	K operator[](T name)
	{
		int ht = hashing(name);
		for (auto it = _table[ht].values.begin();
			it != _table[ht].values.end(); it++)
		{
			if (it->userName == name)
				return(it->userNumber);
		}
		return (K("Not Found"));
	}

};

int main()
{
	hashtable<std::string, std::string> ht;
	info<std::string, std::string> i1, i2, i3;
	i1.userName = "Jack";
	i1.userNumber = "1234";
	i2.userName = "Notavirus";
	i2.userNumber = "323423442";
	ht.add(i1);
	ht.add(i2);
	ht.print();

	std::cout << ht["Jack"] << std::endl;
	system("pause");
	return 0;
}