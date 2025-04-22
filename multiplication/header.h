#ifndef HEADER
#define HEADER
#include <iostream>
#include <iomanip>

int32_t InputQuantityRowsInMatrix(int32_t);
int32_t InputQuantityColsInMatrix(int32_t);
void CreateMatrix(int32_t**&, int32_t, int32_t);
void FillMatrix(int32_t**&, int32_t, int32_t);
void PrintMatrix(int32_t**, int32_t, int32_t);
void CheckingTheConditionForMatrixMultiplication(int32_t, int32_t);
void MatrixMultiplication(int32_t**, int32_t**, int32_t**&, int32_t, int32_t, int32_t);
void DeleteMatrix(int32_t**&, int32_t);

#endif

