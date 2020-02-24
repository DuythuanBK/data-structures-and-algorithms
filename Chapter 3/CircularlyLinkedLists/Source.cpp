#include <iostream>
#include <string>
#include "CircleLinkedList.h"


int main()
{
	CircleLinkedList<std::string> testCircleList;
	testCircleList.add("1");
	testCircleList.add("2");
	testCircleList.add("3");
	testCircleList.add("4");
	testCircleList.add("5");
	testCircleList.add("6");
	testCircleList.add("7");
	testCircleList.add("8");


	while (!testCircleList.empty())
	{
		std::cout << testCircleList.front() << std::endl;
		testCircleList.remove();

	}

	testCircleList.remove();
	system("pause");
	return 0;
}