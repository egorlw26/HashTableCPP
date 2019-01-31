#pragma once
#include "List.h"
#include <random>
#include <time.h>
class HashTable
{
public:
	HashTable(int size);

	int hashFunc(int n);
	void createParams(int &a, int &b, int& p);
	void addElement(int el);
	bool findElem(int el);
	void eraseElem(int el);
	void findMinMax();
	int getMin() { return minLength; }
	int getMax() { return maxLength; }
	void printLists();

	~HashTable();
private:
	bool isSimple(int n);
	int a;
	int b;
	int p;
	int size;
	int minLength;
	int maxLength;
	List* m_lists;

};

