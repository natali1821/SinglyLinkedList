#pragma once
#include <iostream>
#include <utility>
#include <exception>
#include <cstdlib>

template<class T>
class SLL {
private:
	class Node {
	public:
		Node* _next;
		T _data;
		Node(T data) {
			_data = data;
			_next = nullptr;
		}
	};
	Node* _head;
	size_t _size;
	void forceNodeDelete(Node* node);
public:
	class Iterator {
	public:
		using iterator_category = std::forward_iterator_tag;
		using difference_type	= std::ptrdiff_t;
		using value_type		= T;
		using pointer			= T*;
		using reference			= T&;
		Iterator(Node* ptr);
		reference operator*();
		pointer operator->();
		Iterator& operator++(); //prefix
		Iterator operator++(int); //postfix
		bool operator!=(const Iterator& other);
		bool operator==(const Iterator& other);
		difference_type operator-(const Iterator& other);
		Node* getPtr() const;
	private:
		Node* _ptr;
	};

	SLL();

	//the rule of five
	SLL(const SLL& other);
	SLL(SLL<T>&& other) noexcept;

	SLL& operator=(const SLL& other);
	SLL& operator=(SLL<T>&& other) noexcept;

	~SLL();

	const T& at(const size_t pos) const;
	T& at(const size_t pos);
	const T& operator[](const size_t pos) const;
	T& operator[](const size_t pos);
	Node* getNode(const size_t pos) const;

	size_t getIndex(Node* node);

	//insert
	void insert(size_t idx, const T& value);
	void insertAfterNode(Node* node, const T& value);
	void pushBack(const T& value);
	void pushFront(const T& value);

	//remove
	void clear();
	void remove(size_t idx);
	void removeNextNode(Node* node);
	void popBack();
	void popFront();

	// search, Î(n)
	long long int findIndex(const T& value) const;
	Node* findNode(const T& value) const;

	// reverse
	void reverse();
	SLL<T> reverse() const;
	SLL<T> getReverseList() const;

	size_t size() const;
	void print();
	bool isEmpty() const;

	void forEach(T (*fn)(T));
	SLL<T> map(T (*fn)(T));
	void filter(bool (*fn)(T));

	Iterator begin() const;
	Iterator end() const;
};
