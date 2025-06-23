#include <iostream>
#include "header.h"

void InputSize(int32_t& size)
{
	std::cout << "Input size of array ";
	std::cin >> size;

	if (size <= 0)
	{
		throw std::invalid_argument("Wrong size");
	}
}


void createArray(double*& array, int32_t size)
{
	array = new double[size];
}


void CheckingArrayBounds(double min, double max)
{
	if (min > max)
	{
		double temp{ max };
		max = min;
		min = temp;
	}
	if (min == max)
	{
		std::cout << "Bad array bounds";
		exit(0);
	}
	if (max > min)
	{
		std::cout << "Min bound = " << min << '\n';
		std::cout << "Max bound = " << max << '\n';
	}
}



void FillArrayWithRandom(double*& array, int32_t size,double max, double min)
{
	srand(static_cast<unsigned int>(time(NULL)));
	for (int32_t i{}; i < size; ++i)
	{
		array[i] = ((static_cast<double>(rand()) / RAND_MAX) * (max - min)) + min;
	}
}


void FillArrayWithKeyboard(double* array, int32_t size)
{
	for (int32_t i{}; i < size; ++i)
	{
		std::cin >> array[i];
	}
}


void PrintArray(double* array, int32_t size)
{
	for (int32_t i{}; i < size; ++i)
	{
		std::cout << array[i] << ' ';
	}
	std::cout << std::endl;
}


void deleteArray(double*& array, int32_t size)
{
	delete[] array;
}


double MaxElementInArrayByModule(double* array, int32_t size)
{
	double maxElements{ abs(array[0]) };

	for (int32_t i{ 1 }; i < size; ++i)
	{
		if (maxElements < abs(array[i]))
		{
			maxElements = abs(array[i]);
		}
	}
	return maxElements;
}


double SumBetweenTwoPositiveElements(double* array, int32_t size)
{
	int32_t firstPositiveIndex{ -1 };
	int32_t secondPositiveIndex{ -1 };

	std::cout << std::endl;
	
	for (int32_t i{}; i < size; ++i)
	{
		if (array[i] > 0)
		{
			if (firstPositiveIndex == -1)
			{
				firstPositiveIndex = i+1;
			}
			else if (secondPositiveIndex == -1)
			{
				secondPositiveIndex = i-1;
				break;
			}
		}
	}
	if ((firstPositiveIndex == -1) or (secondPositiveIndex == -1) or (firstPositiveIndex > secondPositiveIndex))
	{
		return 0;
	}
	return SumBetweenTwoElements(array, size, firstPositiveIndex, secondPositiveIndex);
}


double SumBetweenTwoElements(double* array, int32_t size, int32_t firstIndex, int32_t secondIndex)
{
	double sum{};
	for (; firstIndex <= secondIndex; ++firstIndex)
	{
		sum += array[firstIndex];
	}
	return sum;
}


double SumBetweenTwoNegativeElements(double* array, int32_t size)
{
	std::cout << std::endl;
	int32_t firstNegativeIndex{ -1 };
	int32_t secondNegativeIndex{ -1 };

	for (int32_t i{}; i < size; ++i)
	{
		if (array[i] < 0)
		{
			if (firstNegativeIndex == -1)
			{
				firstNegativeIndex = i+1;
			}
			else
			{
				secondNegativeIndex = i-1;
			}
		}
	}
	if ((firstNegativeIndex == -1) or (secondNegativeIndex == -1) or (firstNegativeIndex > secondNegativeIndex))
	{
		return 0;
	}
	return SumBetweenTwoElements(array, size, firstNegativeIndex, secondNegativeIndex);
}


void DeleteNumbersWhichAreSmallerXFromArray(double* array, int32_t size)
{
	double temp{};
	double num{};
	
	std::cout << "\nInput min number\n";
	std::cin >> num;

	for (int32_t i{}; i < size - 1; ++i)
	{
		for (int32_t j{}; j < size - i - 1; ++j)
		{
			if (array[j] <= num)
			{
				temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;
			}
		}
	}
	for (int32_t i{}; i < size; ++i)
	{
		if (array[i] < num)
		{
			array[i] = 0;
		}
	}
}