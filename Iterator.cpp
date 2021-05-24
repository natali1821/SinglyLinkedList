#include "SinglyLinkedList.h"

template<class T>
SLL<T>::Iterator::Iterator(Node* ptr) : _ptr(ptr) {}

template<class T>
T& SLL<T>::Iterator::operator*() {
	return _ptr->_data;
}

template<class T>
T* SLL<T>::Iterator::operator->() {
	return &(_ptr->_data);
}

template<class T>
class SLL<T>::Iterator& SLL<T>::Iterator::operator++() {
	_ptr = _ptr->_next;
	return *this;
}

template<class T>
class SLL<T>::Iterator SLL<T>::Iterator::operator++(int) {
	Iterator tmp = *this;
	++(*this);
	return tmp;
}

template<class T>
bool SLL<T>::Iterator::operator!=(const Iterator& other) {
	return _ptr != other._ptr;
}

template<class T>
bool SLL<T>::Iterator::operator==(const Iterator& other) {
	return _ptr == other._ptr;
}

template<class T>
std::ptrdiff_t SLL<T>::Iterator::operator-(const Iterator& other) {
	return _ptr - other._ptr;
}

template<class T>
class SLL<T>::Node* SLL<T>::Iterator::getPtr() const{
	return _ptr;
}
