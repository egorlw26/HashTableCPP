#pragma once
class List
{
public:
	List();

	void push_back(int elem);
	void print();
	bool find(int elem);
	void erase(int elem);
	int getSize() { return size; }

	~List() = default;
private:
	struct Node
	{
		int elem;
		Node* nextNode;
	};
	int size;
	Node* head;
	Node* tail;
};

