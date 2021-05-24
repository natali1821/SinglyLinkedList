#include <iostream>
#include "templates.cpp"

int increment(int a) {
	return ++a;
}

bool evenNumber(int a) {
	return (a % 2 == 0);
}

int main()
{
	SLL<int> first;
	first = SLL<int>();
	first.insert(0, 1);
	first.insert(1, 3);
	first.insert(1, 2);
	first.insert(3, 4);
	first.pushBack(5);
	first.pushFront(0);
	std::cout << "size of first list - " << first.size() << std::endl;
	first.print();

	SLL<int> second(first);
	second.filter(evenNumber);
	std::cout << "size of second list - " << second.size() << std::endl;
	second.print();

	SLL<int> third = first.map(increment);
	std::cout << "size of third list - " << third.size() << std::endl;
	third.print();

	SLL<int>::Iterator cur(third.begin());
	SLL<int>::Iterator tmp(second.end());
	std::cout << *(cur++) << std::endl;
	std::cout << *(cur) << std::endl;
	std::cout << *(++cur) << std::endl;

	SLL<int>::Iterator h(first.begin());
	first.insertAfterNode(h.getPtr(), 9);
	first.removeNextNode(h.getPtr());

	std::cout << h.getPtr() << std::endl;
	std::cout << first.getNode(0) << std::endl;

	first.reverse();
	std::cout << "size of first list - " << first.size() << std::endl;
	first.print();
}
