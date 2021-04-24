#pragma once
#include <iostream>
#include <utility>

class SLL {
public:
	SLL();

	//the rule of five
	SLL(const SLL& other);
	SLL(SLL&& other) noexcept;

	SLL& operator=(const SLL& other);
	SLL& operator=(SLL&& other) noexcept;

	~SLL();

	//methods
	void insert(size_t idx, const int& value);
	void pushBack(const int& value);
	void pushFront(const int& value);

	void clear();
	void erase(size_t idx);
	void popBack();
	void popFront();

	size_t size() const;
	void print();
	bool isEmpty() const;

	void forEach(int (*fn)(int));
	SLL map(int (*fn)(int));
	void filter(bool (*fn)(int));


private:
	class Node {
	public:
		Node* _next;
		int _data;
		Node(int data) {
			_data = data;
			_next = nullptr;
		}
	};
	Node* _head;
	size_t _size;
};
