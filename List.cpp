#include "List.h"
#include <iostream>



List::List()
{
	size = 0;
	head = nullptr;
	tail = nullptr;
}

void List::push_back(int elem)
{
	Node* nNode = new Node;
	nNode->elem = elem;
	nNode->nextNode = nullptr;
	if (size == 0)
	{
		head = nNode;
		tail = nNode;
	}
	else
	{
		tail->nextNode = nNode;
		tail = tail->nextNode;
	}
	size++;
}

void List::print()
{
	Node* node = head;
	while (node != nullptr)
	{
		std::cout << node->elem << ' ';
		node = node->nextNode;
	}
}

bool List::find(int elem)
{
	Node* node = head;
	while (node != nullptr)
	{
		if (node->elem == elem)
			return true;
		node = node->nextNode;
	}
	return false;
}

void List::erase(int elem)
{
	if (find(elem))
	{
		Node* node = new Node;
		if (head->elem == elem)
		{
			node = head;
			head = head->nextNode;
			delete node;
			size--;
			return;
		}

		node = head;
		while (node != nullptr)
		{
			if (node->nextNode->elem == elem)
			{
				if (node->nextNode == tail)
				{
					Node* t = tail;
					tail = node;
					delete t;
					size--;
					return;
				}
				Node* tNode = node->nextNode;
				node->nextNode = node->nextNode->nextNode;
				delete tNode;
				return;
				size--;
			}
		}
	}
}

