#include "SinglyLinkedList.h"

SLL::SLL() {
	_head = nullptr;
	_size = 0;
}

SLL::SLL(const SLL& other) {
	if (other._head) {
		Node* tmp = other._head;
		Node* cur = new Node(tmp->_data);
		_head = cur;
		while(tmp->_next) {
			tmp = tmp->_next;
			cur->_next = new Node(tmp->_data);
			cur = cur->_next;
		}
		_size = other.size();
	}
	else {
		_head = nullptr;
		_size = 0;
	}
}

SLL::SLL(SLL&& other) noexcept{
	_size = std::exchange(other._size, 0);
	_head = std::exchange(other._head, nullptr);
}

SLL& SLL::operator=(const SLL& other){
	if (other.isEmpty()) {
		clear();
		_head = nullptr;
		_size = 0;
		return *this;
	}
	if (this != &other) {
		_size = other.size();
		clear();
		Node* tmp = other._head;
		Node* cur = new Node(tmp->_data);
		_head = cur;
		while(tmp->_next) {
			tmp = tmp->_next;
			cur->_next = new Node(tmp->_data);
			cur = cur->_next;
		}
	}
	return *this;
}

SLL& SLL::operator=(SLL&& other) noexcept{
	if (this != &other) {
		clear();
		_size = std::exchange(other._size, 0);
		_head = std::exchange(other._head, nullptr);
	}
	return *this;
}

SLL::~SLL() {
	clear();
}

void SLL::insert(size_t idx, const ValueType& value) {
	if (idx > size()) {
		throw std::out_of_range("at insert(): position > size of list");
	}
	if (isEmpty()) {
		_head = new Node(value);
		++_size;
		return;
	}
	if (!idx) {
		Node* tmp = _head;
		_head = new Node(value);
		_head->_next = tmp;
	}
	else {
		int pos;
		Node* cur = _head;
		for(pos = 0; pos < idx - 1; ++pos) {
			cur = cur->_next;
		}
		Node* tmp = new Node(value);
		tmp->_next = cur->_next;
		cur->_next = tmp;
	}
	++_size;
}

void SLL::pushBack(const ValueType& value) {
	/*if (!_head) {
		_head = new Node(value);
	}
	else{
		Node* cur = _head;
		while(cur->_next) {
			cur = cur->_next;
		}
		cur->_next = new Node(value);
	}*/
	insert(size(), value);
}

void SLL::pushFront(const ValueType& value) {
	insert(0, value);
}

void SLL::clear(){
	while(_size) {
		popBack();
	}
}

void SLL::erase(size_t idx) {
	if (isEmpty()) {
		return;
	}
	if (idx >= size()) {
		throw std::out_of_range("at erase(): position >= size of list");
	}
	if (!idx) {
		Node* tmp = _head;
		_head = _head->_next;
		delete[] tmp;
	}
	else {
		Node* cur = _head;
		for (int pos = 0; pos < idx - 1; ++pos) {
			cur = cur->_next;
		}
		Node* tmp = cur->_next;
		cur->_next = tmp->_next;
		delete[] tmp;
	}
	--_size;
}

void SLL::popBack() {
	erase(size() - 1);
}

void SLL::popFront() {
	erase(0);
}

size_t SLL::size() const{
	return _size;
}

void SLL::print() {
	if(!_head) {
		std::cout << "nullptr" << std::endl;
	}
	else {
		Node* cur = _head;
		do {
			std::cout << cur->_data << "->";
		} while(cur = cur->_next);
		std::cout << "nullptr" << std::endl;
	}
}

bool SLL::isEmpty() const {
	return !size();
}

void SLL::forEach(ValueType (*fn)(ValueType)) {
	if (isEmpty()) {
		return;
	}
	Node* cur = _head;
	while(cur) {
		cur->_data = fn(cur->_data);
		cur = cur->_next;
	}
}

SLL SLL::map(ValueType (*fn)(ValueType)) {
	SLL tmp(*this);
	tmp.forEach(fn);
	return tmp;
}

void SLL::filter(bool (*fn)(ValueType)) {
	if (isEmpty()) {
		return;
	}
	int pos = 0;
	Node* cur = _head;
	while(cur){
		if (fn(cur->_data)) {
			cur = cur->_next;
		}
		else {
			cur = cur->_next;
			erase(pos);
			--pos;
		}
		++pos;
	}
}

SLL::Iterator SLL::begin() const{
	return SLL::Iterator(_head);
}

SLL::Iterator SLL::end() const {
	return SLL::Iterator(nullptr);
}
//class Iterator
SLL::Iterator::Iterator(Node* ptr) : _ptr(ptr) {}

ValueType& SLL::Iterator::operator*() {
	return _ptr->_data;
}

ValueType* SLL::Iterator::operator->() {
	return &(_ptr->_data);
}

SLL::Iterator& SLL::Iterator::operator++() {
	_ptr = _ptr->_next;
	return *this;
}

SLL::Iterator SLL::Iterator::operator++(int) {
	Iterator tmp = *this;
	++(*this);
	return tmp;
}

bool SLL::Iterator::operator!=(const Iterator& other) {
	return _ptr != other._ptr;
}

bool SLL::Iterator::operator==(const Iterator& other) {
	return _ptr == other._ptr;
}

std::ptrdiff_t SLL::Iterator::operator-(const Iterator& other) {
	return _ptr - other._ptr;
}
