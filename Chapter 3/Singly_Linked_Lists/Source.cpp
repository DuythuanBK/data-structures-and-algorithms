#include <iostream>
#include "MyLinkedList.h""

int main()
{
	MyLinkedList<int> test;
	test.addFront(1);
	test.addFront(2);
	test.addFront(3);
	test.addFront(4);
	test.addFront(5);
	test.removeFront();

	while (!test.empty())
	{
		std::cout << test.front() << std::endl;
		test.removeFront();
	}

	system("pause");
	return 0;
}