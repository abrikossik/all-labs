#include "header.h"

int main()
{
	int32_t rowsOfFirstMatrix{};
	int32_t colsOfFirstMatrix{};
	int32_t rowsOfSecondMatrix{};
	int32_t colsOfSecondMatrix{};

	std::cout << "Input size of first matrix\n";

	int32_t** firstMatrix{};
	int32_t** secondMatrix{};

	rowsOfFirstMatrix = InputQuantityRowsInMatrix(rowsOfFirstMatrix);
	colsOfFirstMatrix = InputQuantityColsInMatrix(colsOfFirstMatrix);
	CreateMatrix(firstMatrix,rowsOfFirstMatrix, colsOfFirstMatrix);
	FillMatrix(firstMatrix, rowsOfFirstMatrix, colsOfFirstMatrix);

	std::cout << "Input size of second matrix\n";

	rowsOfSecondMatrix = InputQuantityRowsInMatrix(rowsOfSecondMatrix);
	colsOfSecondMatrix = InputQuantityColsInMatrix(colsOfSecondMatrix);
	CheckingTheConditionForMatrixMultiplication(rowsOfFirstMatrix, colsOfSecondMatrix);
	CreateMatrix(secondMatrix,rowsOfSecondMatrix, colsOfSecondMatrix);
	FillMatrix(secondMatrix, rowsOfSecondMatrix, colsOfSecondMatrix);

	int32_t** thirdMatrix{};
	CreateMatrix(thirdMatrix, rowsOfFirstMatrix, colsOfSecondMatrix);
	MatrixMultiplication(firstMatrix, secondMatrix, thirdMatrix, rowsOfFirstMatrix, colsOfFirstMatrix, colsOfSecondMatrix);
	PrintMatrix(thirdMatrix, rowsOfFirstMatrix, colsOfSecondMatrix);
	DeleteMatrix(firstMatrix, rowsOfFirstMatrix);
	DeleteMatrix(secondMatrix, rowsOfSecondMatrix);
	DeleteMatrix(thirdMatrix, rowsOfFirstMatrix);

	return 0;
}