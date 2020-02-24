#include <iostream>
#include <string>
#include "MyDLinkedList.h"

int main()
{
	MyDLinkedList<int> Dlist;
	Dlist.push_front(1);
	Dlist.push_front(2);
	Dlist.push_front(3);
	Dlist.push_front(4);
	Dlist.push_front(5);
	Dlist.push_front(6);
	Dlist.push_front(7);

	while (!Dlist.empty())
	{
		std::cout << Dlist.back() << std::endl;
		Dlist.pop_back();
	}

	system("pause");
	return 0;
}