#include "header.h"
bool InputSizeMatrix(int32_t& size)
{
	std::cout << "Input size of matrix \n";
	std::cin >> size;

	return (size > 0);
}


void CreateSquareMatrix(int32_t**& matrix, int32_t size)
{
	matrix = new int32_t* [size];
	for (int32_t i{}; i < size; ++i)
	{
		matrix[i] = new int32_t[size];
	}
}


void CreateMatrix(int32_t**& matrix, int32_t rows,int32_t cols)
{
	matrix = new int32_t * [rows];
	for (int32_t i{}; i < rows; ++i)
	{
		matrix[i] = new int32_t[cols];
	}
}


void FillSquareMatrix(int32_t**& matrix, int32_t size)
{
	std::cout << "Input elements of matrix \n";
	for (int32_t i{}; i < size; ++i)
	{
		for (int32_t j{}; j < size; ++j)
		{
			std::cin >> matrix[i][j];
		}
	}
}

void FillMatrix(int32_t**& matr, int32_t rows,int32_t cols)
{
	std::cout << "Input elements of matrix \n";
	for (int32_t i{}; i < rows; ++i)
	{
		for (int32_t j{}; j < cols; ++j)
		{
			std::cin >> matr[i][j];
		}
	}
}


int32_t FindMinAndMaxElements(int32_t** matrix, int32_t size, int32_t& maxElements,int32_t& minElements)
{
	int32_t max{matrix[0][0]};
	int32_t min{matrix[0][0]};

	for (int32_t i{}; i < size; ++i)
	{
		for (int32_t j{}; j < size; ++j)
		{
			if (matrix[i][j] >= max)
			{
				maxElements = j;
				max = matrix[i][j];
			}
			else
			{
				minElements = i;
				min = matrix[i][j];
			}
		}
	}
	return(maxElements, minElements);
}


int32_t ScalarMultiplication(int32_t** matr, int32_t rows, int32_t max, int32_t min)
{
	int32_t result{};
	for (int32_t i{}; i < rows; ++i)
	{
		result += matr[min][i] * matr[i][max];
	}
	return result;
}


int32_t MinElKForRows(int32_t** matr, int32_t rows, int32_t min)
{
	min = INT_MAX;
	int32_t maxELinRows{};

	for (size_t i{}; i < rows; ++i)
	{
		maxELinRows = matr[i][0];
		for (size_t j{}; j < rows; ++j)
		{
			if (maxELinRows < matr[i][j])
			{
				maxELinRows = matr[i][j];
			}
		}
		if (maxELinRows < min)
		{
			min = maxELinRows;
		}
	}

	return (min+1);
}


int32_t FindNumberOfStringWithZero(int32_t** matr, int32_t rows, int32_t cols)
{
	for (size_t i{}; i < rows; ++i)
	{
		for (size_t j{}; j < cols; ++j)
		{
			if (matr[i][j] == 0)
			{
				return (i + 1);
			}
		}
	}
	return -1;
}


void FindSaddlePointOfMatrix(int32_t** matrix, int32_t rows, int32_t cols)
{
	bool found {true};

	for (size_t i{}; i < rows;++i)
	{
		int32_t minRowVal = matrix[i][0];
		int32_t minColIndex = 0;

		for (size_t j{ 1 }; j < cols; ++j)
		{
			if (matrix[i][j] < minRowVal) 
			{
				minRowVal = matrix[i][j];
				minColIndex = j;
			}
		}

		bool isSaddlePoint{ true };
		
		for (size_t k{ 0 }; k < rows; ++k) 
		{
			if (matrix[k][minColIndex] > minRowVal)
			{
				isSaddlePoint = false;
				break;
			}
		}

		if (isSaddlePoint) {
			std::cout << "String " << i + 1 << ", Rows " << minColIndex + 1 << '\n';
			found = true;
		}
	}

	if (!found) {
		std::cout << "No one the saddle point.\n";
	}
	}


void PrintMatrix(int32_t** matrix, int32_t rows)
{
	for (int32_t i{}; i < rows; ++i)
	{
		for (int32_t j{}; j < rows; ++j)
		{
			std::cout << std::setw(6) << matrix[i][j];
		}
		std::cout << '\n';
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