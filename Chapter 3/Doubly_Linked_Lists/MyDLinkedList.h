#ifndef __MYDLINKEDLIST__
#define __MYDLINKEDLIST__

template <typename T>
class DNode{
private:
    T t;
    DNode* prev;
    DNode* next;
    template <typename T>
    friend class MyDLinkedList;
};

template <typename T>
class MyDLinkedList{
public:
    MyDLinkedList();
    ~MyDLinkedList();
    bool empty() const;
    const T& front() const;
    const T& back() const;
    void push_front(const T& t);
    void push_back(const T& t);
    void pop_front();
    void pop_back();

private:
    DNode<T>* header;
    DNode<T>* tailer;

protected:
	void add(DNode<T>* v, const T& e);
	void remove(DNode<T> *v);
};

template <typename T> 
MyDLinkedList<T>::MyDLinkedList()
{
    header = new DNode<T>;
    tailer = new DNode<T>;
    header->next = tailer;
    tailer->prev = header;    
}

template <typename T>
MyDLinkedList<T>::~MyDLinkedList()
{
	while (!empty())
		pop_front();
	delete header;
	delete tailer;
}

template <typename T>
bool MyDLinkedList<T>::empty() const
{
	return (header->next == tailer);
}

template <typename T>
const T& MyDLinkedList<T>::front() const
{
	if (empty())
		throw "Double linked list is empty";
	else
		return header->next->t;
}

template <typename T>
const T& MyDLinkedList<T>::back() const
{
	if (empty())
		throw "Double linked list is empty";
	else
		return tailer->prev->t;
}

template <typename T>
void MyDLinkedList<T>::push_front(const T& e)
{
	add(header->next, e);
}

template <typename T>
void MyDLinkedList<T>::push_back(const T& e)
{
	add(tailer, e);
}

template <typename T>
void MyDLinkedList<T>::add(DNode<T>* v, const T& e)
{
	DNode<T>* newNode = new DNode<T>;
	newNode->t = e;

	newNode->next = v;
	newNode->prev = v->prev;
	newNode->prev->next = newNode;
	v->prev = newNode;
}

template <typename T>
void MyDLinkedList<T>::pop_front()
{
	if (empty())
	{
		throw "Double linked list is empty";
	}
	else
	{
		remove(header->next);
	}
}

template <typename T>
void MyDLinkedList<T>::pop_back()
{
	if (empty())
	{
		throw "Double linked list is empty";
	}
	else
	{
		remove(tailer->prev);
	}
}
template <typename T>
void MyDLinkedList<T>::remove(DNode<T> *v)
{
	DNode<T>* u = v->prev;
	DNode<T>* w = v->next;
	u->next = w;
	w->prev = u;
}

#endif