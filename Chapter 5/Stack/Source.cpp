#include <iostream>
#include <string>

class RuntimeException { // generic run-time exception
private:
	std::string errorMsg;
public:
	RuntimeException(const std::string& err) { errorMsg = err; }
	std::string getMessage() const { return errorMsg; }
};

class StackEmpty : public RuntimeException {
public:
	StackEmpty(const std::string& err) : RuntimeException(err) {}
};

class StackFull : public RuntimeException {
public:
	StackFull(const std::string& err) : RuntimeException(err) {}
};


template <typename E>
class Stack {
	enum {DEF_CAPACITY = 100};
public:
	Stack(int cap = DEF_CAPACITY);
	int size() const;
	bool empty() const;
	const E& top() const throw(StackEmpty);
	void push(const E& e);
	void pop() throw(StackEmpty);

private:
	E* s;
	int capacity;
	int t;
};



template<typename E> Stack<E>::Stack(int cap)
{
	s = new E[cap];
	capacity = cap;
	t = -1;
}

template<typename E> int Stack<E>::size() const
{
	return (t + 1);
}

template<typename E> bool Stack<E>::empty() const
{
	return (t < 0);
}

template<typename E>
const E& Stack<E>::top() const throw(StackEmpty)
{
	if (empty())
		throw StackEmpty("Top of empty stack");
	return s[t];
}

template <typename E>
void Stack<E>::push(const E& e) throw(StackFull) 
{
	if (size() == capacity) 
		throw StackFull("Full to full stack");  
	s[++t] = e;
}

template <typename E>
void Stack<E>::pop() throw(StackEmpty)
{
	if (empty())
		throw StackEmpty("Pop from empty stack");
	--t;
}

// Check parentheis matching in string. 
// For example: ()()()()()() -> return 1  ;  )(( -> return 0.
bool ParenMatch(char s[], int n)
{
	Stack<char> stack;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '(')
		{
			stack.push(s[i]);
		}
		else if (s[i] == ')')
		{
			if (stack.empty())
				return false;
			if (stack.top() != '(')
				return false;
			stack.pop();
		}
	}
	if (stack.empty())
		return true;
	else
		return false;
}

int main()
{
	
	char parenString[] = "adfadsf(afasdf)()()";

	std::cout << ParenMatch(parenString, strlen(parenString));
	


	std::cout << std::endl;
	std::cin.get();

	return 0;
}