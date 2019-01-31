#include "HashTable.h"



HashTable::HashTable(int size)
{
	this->size = size;
	m_lists = new List[size];
	createParams(a, b, p);
}

int HashTable::hashFunc(int k)
{
	return ((a*k + b))%size;
}

void HashTable::createParams(int & a, int & b, int & p)
{
	srand(time(NULL));
	a = rand() % 300 + 10;
	b = rand() % 300 + 10;
	p = this->size;
	while (!isSimple(p))
		p++;
}

void HashTable::addElement(int el)
{
	int number = hashFunc(el);
	m_lists[number].push_back(el);
}

bool HashTable::findElem(int el)
{
	int number = hashFunc(el);
	return m_lists[number].find(el);
}

void HashTable::eraseElem(int el)
{
	int number = hashFunc(el);
	m_lists[number].erase(el);
}

void HashTable::findMinMax()
{
	maxLength = 0;
	minLength = size * 100;
	for (int i = 0; i < size; i++)
	{
		if (m_lists[i].getSize() > maxLength)
			maxLength = m_lists[i].getSize();
		if (m_lists[i].getSize() < minLength)
			minLength = m_lists[i].getSize();
	}
}


void HashTable::printLists()
{
}

HashTable::~HashTable()
{
}

bool HashTable::isSimple(int n)
{
	for (int i = 2; i <= sqrt(n); i++)
		if (n%i == 0)
			return false;
	return true;
}
