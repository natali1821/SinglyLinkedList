#pragma once
#include <iostream>
#include <utility>
#include <exception>
#include <cstdlib>

using ValueType = int;

class SLL {
private:
	class Node {
	public:
		Node* _next;
		ValueType _data;
		Node(ValueType data) {
			_data = data;
			_next = nullptr;
		}
	};
	Node* _head;
	size_t _size;
public:
	class Iterator {
	public:
		using iterator_category = std::forward_iterator_tag;
		using difference_type	= std::ptrdiff_t;
		using value_type		= ValueType;
		using pointer			= ValueType*;
		using reference			= ValueType&;
		Iterator(Node* ptr);
		reference operator*();
		pointer operator->();
		Iterator& operator++(); //prefix
		Iterator operator++(int); //postfix
		bool operator!=(const Iterator& other);
		bool operator==(const Iterator& other);
		difference_type operator-(const Iterator& other);
	private:
		Node* _ptr;
	};

	SLL();

	//the rule of five
	SLL(const SLL& other);
	SLL(SLL&& other) noexcept;

	SLL& operator=(const SLL& other);
	SLL& operator=(SLL&& other) noexcept;

	~SLL();

	//methods
	void insert(size_t idx, const ValueType& value);
	void pushBack(const ValueType& value);
	void pushFront(const ValueType& value);

	void clear();
	void erase(size_t idx);
	void popBack();
	void popFront();

	size_t size() const;
	void print();
	bool isEmpty() const;

	void forEach(ValueType (*fn)(ValueType));
	SLL map(ValueType (*fn)(ValueType));
	void filter(bool (*fn)(ValueType));

	Iterator begin() const;
	Iterator end() const;
};
