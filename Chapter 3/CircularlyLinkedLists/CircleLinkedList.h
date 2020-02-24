#ifndef __CIRCLELINKEDLIST__
#define __CIRCLELINKEDLIST__

template <typename T>
class CNode {
private:
	T t;
	CNode* next;

	template <typename T>
	friend class CircleLinkedList;
};

template <typename T>
class CircleLinkedList {
public:
	CircleLinkedList();
	~CircleLinkedList();
	bool empty() const;
	const T& front() const;
	const T& back() const;
	void advance();
	void add(const T& e);
	void remove();

private:
	CNode<T>* cursor;
};

template <typename T>
CircleLinkedList<T>::CircleLinkedList()
{
	cursor = nullptr;
}

template <typename T>
CircleLinkedList<T>::~CircleLinkedList()
{
	while (!empty())
	{
		remove();
	}
}

template <typename T>
bool CircleLinkedList<T>::empty() const
{
	return (cursor == nullptr);
}

template <typename T>
void CircleLinkedList<T>::add(const T& e)
{
	CNode<T>* newNode = new CNode<T>;
	newNode->t = e;
	if (cursor == nullptr)
	{
		cursor = newNode;
		cursor->next = cursor;
	}
	else
	{
		newNode->next = cursor->next;
		cursor->next = newNode;
	}
}

template <typename T>
const T& CircleLinkedList<T>::front() const
{
	if (empty())
	{
		throw "List empty";
	}
	else
	{
		return cursor->next->t;
	}
}

template <typename T>
const T& CircleLinkedList<T>::back() const
{
	if (empty())
	{
		throw "List empty";
	}
	else
	{
		return cursor->next;
	}
}

template <typename T>
void CircleLinkedList<T>::advance()
{
	cursor = cursor->next;
}

template <typename T>
void CircleLinkedList<T>::remove()
{
	CNode<T>* oldNode = cursor->next;
	if (oldNode == cursor)
	{
		cursor = nullptr;
	}
	else
	{
		cursor->next = oldNode->next;
	}
	delete oldNode;
}

#endif // !__CIRCLELINKEDLIST__

