/*Хеш-таблица - динамическая структура данных, которая реализует интерфейс ассоциативного массива,
то есть позволяет хранить пару <Ключ, Значение> и выполнять 3 операции: добавление новой пары,
операции поиска, операции удаления по ключу.*/

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>

#define SIZE 16

template<typename T>
class HashTable
{
protected:
	std::vector<std::list<std::pair<std::string, T>>> table;// vector<list<T>>

public:
	HashTable();
	~HashTable();
	unsigned int HashFAQ6(std::string);
	HashTable<T>& add(std::pair<std::string, T>&);
	void print();
	std::string operator[](T);
	HashTable<T>& erase(T name);
	typename std::list<std::pair<std::string, T>>::iterator find(T name);
};

template<typename T>
HashTable<T>::HashTable()
{
	table.resize(SIZE);
}

template<typename T>
HashTable<T>::~HashTable()
{
}

// Хеш-функция Дженкинса
template<typename T>
unsigned int HashTable<T>::HashFAQ6(std::string data)
{
	unsigned int hash = 0;
	for (char c: data)
	{
		hash += (unsigned int)(c);
		hash += (hash << 10);
		hash ^= (hash >> 6);
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);
	return hash % table.size();
}

template<typename T>
HashTable<T>& HashTable<T>::add(std::pair<std::string, T>& data)
{
	unsigned int key = 0;
	key = HashFAQ6(data.second);
	table[key].push_front(data);
	return *this;
}

template<typename T>
void HashTable<T>::print()
{
	for (unsigned i = 0; i < table.size(); i++)
	{
		std::cout << "HashTable[" << i << "]:" << std::endl;
		if (!table[i].empty())
			for (auto it = table[i].begin(); it != table[i].end(); it++)
			{
				std::cout << "Number:" << it->first << std::endl;
				std::cout << "Person:" << it->second << std::endl;
			}
		else
			std::cout << "...." << std::endl;
	}
}

template<typename T>
std::string HashTable<T>::operator[](T name)
{
	unsigned int key = 0;
	key = HashFAQ6(name);
	for (auto it : table[key])
	{
		if (it.second == name)
			return it.first;
	}
	return "0";
}

template<typename T>
HashTable<T>& HashTable<T>::erase(T name)
{
	unsigned int key = 0;
	key = HashFAQ6(name);
	for (auto it : table[key])
	{
		if (it.second == name)
		{
			table[key].remove(it);
			return *this;// break;
		}
	}
	return *this;
}

template<typename T>
typename std::list<std::pair<std::string, T>>::iterator HashTable<T>::find(T name)
{
	unsigned int key = 0;
	key = HashFAQ6(name);
	for (auto it = table[key].begin(); it != table[key].end(); ++it)
	{
		if (it->second == name)
			return it;
	}
	return table[key].end();
}

//////////////////////
//////////////////////
//////////////////////
//////мне//пизда//////
//////////////////////
//////////////////////
//////////////////////