#include <iostream>
#include <string>

class StringNode {
private:
	std::string elem;
	StringNode* next;

	friend class StringLinkedList;
};

class StringLinkedList {
public:
	StringLinkedList();
	~StringLinkedList();
	bool empty() const;
	const std::string& front() const;
	void addFront(const std::string& e);
	void removeFront();

private:
	StringNode* head;
};


StringLinkedList::StringLinkedList() : head(NULL) {}

StringLinkedList::~StringLinkedList()
{
	while (!empty())
	{
		removeFront();
	}
}

bool StringLinkedList::empty() const
{
	return (head == NULL);
}

const std::string& StringLinkedList::front() const
{
	return (head->elem);
}

void StringLinkedList::addFront(const std::string& e)
{
	StringNode*v = new StringNode;
	v->elem = e;			// store data
	v->next = head;			// head now follows v
	head = v;			// v is now the head
}

void StringLinkedList::removeFront()
{

}
int main()
{
	std::cout << "adsfkajsdflkja" << std::endl;
	system("pause");
	return 0;
}