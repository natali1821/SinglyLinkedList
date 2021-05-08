#include <iostream>
#include "SinglyLinkedList.h"

int increment(int a) {
	return ++a;
}

bool evenNumber(int a) {
	return (a % 2 == 0);
}

int main()
{
	SLL first;
	first = SLL();
	first.insert(0, 1);
	first.insert(1, 3);
	first.insert(1, 2);
	first.insert(3, 4);
	first.pushBack(5);
	first.pushFront(0);
	std::cout << first.size() << std::endl;
	first.print();

	SLL second(first);
	second.filter(evenNumber);
	std::cout << second.size() << std::endl;
	second.print();

	SLL third = first.map(increment);
	std::cout << third.size() << std::endl;
	third.print();

	SLL::Iterator cur(third.begin());
	SLL::Iterator tmp(second.end());
	std::cout << *(cur++) << std::endl;
	std::cout << *(cur) << std::endl;
	std::cout << *(++cur) << std::endl;
}
