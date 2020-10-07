#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <cstdlib>
#include <iostream>

const size_t X = 3;

struct TVector {
	size_t iSize;
	double iData[X];	// double iColumn[X];
};

inline int Set(TVector* aVector, size_t aPosition, double aValue) {
	if ((aPosition >= aVector->iSize)) return 1;
	aVector->iData[aPosition] = aValue;
	return 0;
}

inline double Get(const TVector* aVector, size_t aPosition) {
	if (aVector == nullptr)
		exit(1);
	if (aPosition >= aVector->iSize)
		throw std::out_of_range("The position of a wanted value is out of range!");		// an EXCEPTION example
	return aVector->iData[aPosition];
}

inline void Print(TVector* aVector) {
	for (size_t k = 0; k < aVector->iSize; k++) {
		printf("%f", Get(aVector, k));
		std::cout << '\n';
	}
	std::cout << '\n';
}

int Add(TVector aAddVector1, TVector aAddVector2, TVector* aAddRes);
TVector* Sub(TVector* aSubVector1, TVector* aSubVector2);

#endif /* _VECTOR_H_ */