#include <iostream>

int sumMatrix(int A[][3], int m, int n);

int sumArray(int A[][3], int m, int n);

int main()
{
	int A[3][3] = { {1, 1, 1},
					{1, 1, 1},
					{1, 1, 1},
					};
	std::cout << "Sum = ";
	std::cout << " = "<< sumMatrix(A, 3, 3) << std::endl;
	std::cin.get();
	return 0;
}

int sumMatrix(int A[][3], int m, int n)
{
	if (m == 0)
		return 0;
	else
	{
		return sumMatrix(A, m - 1, n) + sumArray(A, m - 1, n - 1);
	}
}

int sumArray(int A[][3], int m, int n)
{
	if (n == 0)
	{
		std::cout << "A[" << m << "]" << "[" << n << "] + ";
		return A[m][n];
	}
	else
	{
		std::cout << "A[" << m << "]" << "[" << n << "] + ";
		return sumArray(A, m, n - 1) + A[m][n];
	}
}