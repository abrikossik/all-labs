#ifndef HEADER
#define HEADER

#include <iostream>
#include <iomanip>

bool InputSizeMatrix(int32_t&);
void CreateSquareMatrix(int32_t**&, int32_t);
void CreateMatrix(int32_t**&, int32_t,int32_t);
void FillSquareMatrix(int32_t**&, int32_t);
void FillMatrix(int32_t**&, int32_t,int32_t);
int32_t FindMinAndMaxElements(int32_t**, int32_t, int32_t&, int32_t&);
int32_t ScalarMultiplication(int32_t**, int32_t, int32_t, int32_t);
int32_t MinElKForRows(int32_t**, int32_t, int32_t);
int32_t FindNumberOfStringWithZero(int32_t**, int32_t, int32_t);
void FindSaddlePointOfMatrix(int32_t**, int32_t, int32_t);
void PrintMatrix(int32_t**, int32_t);
void DeleteMatrix(int32_t**&, int32_t);

#endif