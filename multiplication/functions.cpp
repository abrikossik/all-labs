#include "header.h"

int32_t InputQuantityRowsInMatrix(int32_t rows)
{
	std::cout << "Input quantity of rows in matrix\n";
	std::cin >> rows;
	if (rows <= 0)
	{
		throw std::invalid_argument("Wrong size");
	}
	return rows;
}


int32_t InputQuantityColsInMatrix(int32_t cols)
{
	std::cout << "Input quantity of cols in matrix\n";
	std::cin >> cols;
	if (cols <= 0)
	{
		throw std::invalid_argument("Wrong size");
	}
	return cols;
}


void CreateMatrix(int32_t**& matrix, int32_t rows, int32_t cols)
{
	matrix = new int32_t * [rows];
	for (int32_t i{}; i < rows; ++i)
	{
		matrix[i] = new int32_t[cols];
	}
}


void FillMatrix(int32_t**& matrix, int32_t rows, int32_t cols)
{
	std::cout << "Input elements of matrix\n";
	for (int32_t i{}; i < rows; ++i)
	{
		for (int32_t j{}; j < cols; ++j)
		{
			std::cin >> matrix[i][j];
		}
	}
}


void PrintMatrix(int32_t** matrix, int32_t rows, int32_t cols)
{
	for (int32_t i{}; i < rows; ++i)
	{
		for (int32_t j{}; j < cols; ++j)
		{
			std::cout << std::setw(6) << matrix[i][j];
		}
		std::cout << '\n';
	}
}


void CheckingTheConditionForMatrixMultiplication(int32_t rows, int32_t cols)
{
	if ((rows > cols) || (rows < cols))
	{
		std::cout << "matrices cannot be multiplied";
	}
}


void MatrixMultiplication(int32_t** firstMatrix, int32_t** secondMatrix, int32_t**& thirdMatrix, int32_t rowsOfFirstMatrix, int32_t colsOfFirstMatrix, int32_t colsOfSecondMatrix)
{
	int32_t elementsOFThirdMatrix{};
	for (int32_t i{}; i < rowsOfFirstMatrix; ++i)
	{
		for (int32_t j{}; j < colsOfSecondMatrix; ++j)
		{
			for (int32_t k{}; k < colsOfFirstMatrix; ++k)
			{
				elementsOFThirdMatrix += firstMatrix[i][k] * secondMatrix[k][j];
			}
			thirdMatrix[i][j] = elementsOFThirdMatrix;
			elementsOFThirdMatrix = 0;
		}
	}
}


void DeleteMatrix(int32_t**& matrix, int32_t rows)
{
	for (int32_t i{}; i < rows; ++i)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}