#include <iostream>

template <typename E>
class Quence
{
	enum {MAX_SIZE = 100};
public:
	int size() const;
	bool empty() const;
	const E& front() const;
	void enquence(const E& e);
	void dequence();
private:
	E *q;
	int n;
	int r;
	int f;
};

template <typename E> 
int Quence<E>::size() const { return n; }

template <typename E>
bool Quence<E>::empty() const
{
	return (n == 0);
}

template <typename E>
void Quence<E>::enquence(const E& e)
{
	if (size() == MAX_SIZE - 1)
	{
		std::cout << "Quence full" << std::endl;
		return;
	}
	else
	{
		r = (r + 1) % MAX_SIZE;
		n = n + 1;
		q[r] = e;
	}
}

template <typename E>
void Quence<E>::dequence()
{
	f = (f + 1) / N;
	n = n - 1;
}

template <typename E>
const E& Quence<E>::front() const
{
	if (empty())
	{
		std::cout << "Quence empty" << std::endl;
	}
	else
	{
		return q[f];
	}
}


int main()
{

	std::cin.get();
	return 0;
}