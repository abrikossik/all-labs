#include "header.h"

int main()
{
	std::cout << "How do you want to enter the array? (if from the keyboard than write 1, random write 0)" << std::endl;
	int16_t inputType{};
	std::cin >> inputType;
	switch (inputType)
	{
	case 1:
	{
		int32_t size{};
		try
		{
			InputSize(size);
			double* array = nullptr;
			createArray(array, size);
			FillArrayWithKeyboard(array, size);
			std::cout << MaxElementInArrayByModule(array, size);
			std::cout << SumBetweenTwoPositiveElements(array, size);
			std::cout << SumBetweenTwoNegativeElements(array, size);
			DeleteNumbersWhichAreSmallerXFromArray(array, size);
			deleteArray(array, size);
		}
		catch (std::invalid_argument& e)
		{
			std::cout << e.what();
		}
		break;
	}
	case 0:
	{
		int32_t size{};
		try
		{
			InputSize(size);
			double* array = nullptr;
			createArray(array, size);

			double min{};
			double max{};
			std::cout << "Input bounds of numbers in array\n";
			std::cin >> min >> max;

			CheckingArrayBounds(min, max);
			FillArrayWithRandom(array, size,min,max);
			PrintArray(array, size);
			std::cout << MaxElementInArrayByModule(array, size);
			std::cout << SumBetweenTwoPositiveElements(array, size);
			std::cout << SumBetweenTwoNegativeElements(array, size);
			DeleteNumbersWhichAreSmallerXFromArray(array, size);
			PrintArray(array, size);
			deleteArray(array, size);
		}
		catch (std::invalid_argument& e)
		{
			std::cout << e.what();
		}
		break;
	}
	default:
		std::cout << "Try again (0 or 1)\n";
		break;
	}
	return 0;
}