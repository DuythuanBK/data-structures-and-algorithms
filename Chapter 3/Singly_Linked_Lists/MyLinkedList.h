#pragma once
#include <iostream>
template<typename T>
class Node
{
private:
	T t;
	Node *next;
	template<typename T>
	friend class MyLinkedList;
};

template<typename T>
class MyLinkedList
{
public:
	MyLinkedList();
	~MyLinkedList();
	bool empty() const;
	const T& front() const;
	void addFront(const T& t);
	void removeFront();
	void printLinkedList();

private:
	Node<T>* head;
};

template<typename T>
MyLinkedList<T>::MyLinkedList()
{
	head = nullptr;
}

template<typename T>
MyLinkedList<T>::~MyLinkedList()
{
	while (!empty())
	{
		removeFront();
	}
}

template<typename T>
bool MyLinkedList<T>::empty() const
{
	return (head == nullptr);
}

template<typename T>
const T& MyLinkedList<T>::front() const
{
	return head->t;
}

template<typename T>
void MyLinkedList<T>::addFront(const T& e)
{
	Node<T>* newNode = new Node<T>;
	newNode->t = e;
	newNode->next = head;
	head = newNode;
}


template<typename T>
void MyLinkedList<T>::removeFront()
{
	if (empty())
	{
		throw "Linkes list is empty!";
	}
	else
	{
		Node<T>* oldHead = head;
		head = head->next;
		delete oldHead;
	}
}

template<typename T>
void MyLinkedList<T>::printLinkedList()
{
	Node* iNode = head;
	int i = 0;
	while (iNode->next != nullptr)
	{
		std::cout << i << ": " << iNode->t << std::endl;
	}
}