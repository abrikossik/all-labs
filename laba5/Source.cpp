#include "header.h"

int main()
{
	int32_t rows{};
	int32_t cols{};
	int32_t** squareMatrix{};
	int32_t minElements{};
	int32_t maxElements{};

	InputSizeMatrix(rows);
	CreateSquareMatrix(squareMatrix, rows);
	FillSquareMatrix(squareMatrix, rows);
	FindMinAndMaxElements(squareMatrix, rows, maxElements, minElements);

	int32_t result{ScalarMultiplication(squareMatrix,rows,maxElements,minElements)};

	std::cout << result;

	result = MinElKForRows(squareMatrix, rows, maxElements);

	std::cout << '\n' << result << '\n';

	int32_t** matrix{};

	InputSizeMatrix(rows);
	InputSizeMatrix(cols);
	CreateMatrix(matrix,rows,cols);
	FillMatrix(matrix, rows, cols);

	result = FindNumberOfStringWithZero(matrix, rows, cols);

	if (result == -1)
	{
		std::cout << "No one Zero in matrix \n";
	}
	else
	{
		std::cout << result;
	}

	FindSaddlePointOfMatrix(matrix, rows, cols);

	return 0;
}