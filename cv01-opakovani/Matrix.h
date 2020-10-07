#ifndef _MATRIX_H_
#define _MATRIX_H_

#include "Vector.h"

const size_t Y = 3;

struct TMatrix {
	size_t iSize;
	TVector iData[Y];	// TVector iRow[Y];
};

inline int Set(TMatrix* aMatrix, size_t aRowIndex, size_t aColIndex, double aValue) {
	if (aMatrix == nullptr || aRowIndex >= aMatrix->iSize || aColIndex >= aMatrix->iData->iSize) return 1;
	aMatrix->iData[aRowIndex].iData[aColIndex] = aValue;
	return 0;
}

inline double Get(const TMatrix* aMatrix, size_t aRowIndex, size_t aColIndex) {
	if (aMatrix == nullptr)
		exit(1);
	if (aRowIndex >= aMatrix->iSize || aColIndex >= aMatrix->iData->iSize)
		throw std::out_of_range("The position of a wanted value is out of range!");		// an EXCEPTION example
	return aMatrix->iData[aRowIndex].iData[aColIndex];
}

inline void Print(TMatrix* aMatrix) {
	for (size_t i = 0; i < aMatrix->iData->iSize; i++) {
		for (size_t j = 0; j < aMatrix->iSize; j++) {
			printf("%f", Get(aMatrix, j, i));
			std::cout << '\t';	
		}						
		std::cout << '\n';		
	}							
	std::cout << '\n' << '\n';	
}

int Add(TMatrix aAddMatrix1, TMatrix aAddMatrix2, TMatrix* aAddRes);
TMatrix* Sub(TMatrix* aSubMatrix1, TMatrix* aSubMatrix2);
#endif // !_MATRIX_H_
