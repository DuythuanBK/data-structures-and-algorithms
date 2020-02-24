#include <iostream>

#define N 4


void printMatrix(int A[][N], int m, int n)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) 
		{
			std::cout << A[i][j] << "   ";
		}
		std::cout << std::endl;
	}
}

int main()
{
	int A[N][N] = { {1, 2, 3, 4},
					{5, 6, 7, 8},
					{9, 10, 11, 12},
					{13, 14, 15, 16} };

	int count = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if ((i != j) && (i + j == count))
			{
				int temp = A[i][j];
				A[i][j] = A[j][i];
				A[j][i] = temp;
				count++;
			}
			if (count == N)
				break;
		}
		if (count == N)
			break;
	}
	printMatrix(A, 3, 3);

	std::cin.get();
	return 0;
}