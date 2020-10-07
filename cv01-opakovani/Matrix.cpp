#include "Matrix.h"
#include "c:\GitHub\BPC-PPC\checker\check.h"

using std::cerr;

int Add(TMatrix aAddMatrix1, TMatrix aAddMatrix2, TMatrix* aAdd_Result_ptr) {
	if (aAdd_Result_ptr == nullptr ||
		aAddMatrix1.iData == nullptr ||
		aAddMatrix2.iData == nullptr ||
		aAddMatrix1.iData->iData == nullptr ||
		aAddMatrix2.iData->iData == nullptr ||
		aAddMatrix1.iSize != aAddMatrix2.iSize ||
		aAddMatrix1.iSize != aAdd_Result_ptr->iSize ||
		aAddMatrix1.iData->iSize != aAddMatrix2.iData->iSize ||
		aAddMatrix1.iData->iSize != aAdd_Result_ptr->iData->iSize)
		return 1;

	for (size_t i = 0; i < aAddMatrix1.iData->iSize; i++) {
		for (size_t j = 0; j < aAddMatrix1.iSize; j++) {
			aAdd_Result_ptr->iData[i].iData[j] = aAddMatrix1.iData[i].iData[j] + aAddMatrix2.iData[i].iData[j];
			std::cout << '\t';
		}
		std::cout << '\n';
	}
	return 0;
}

TMatrix* Sub(TMatrix* aSubMatrix1, TMatrix* aSubMatrix2) {
	TMatrix* Sub_Result_p = (TMatrix*)calloc(1, sizeof(TMatrix));
	if (Sub_Result_p == nullptr) {
		cerr << "Allocation failed!" << '\n';			// std::endl vlozi "\n" (line feed)
		free(Sub_Result_p);
		exit(1);
	}
	if (aSubMatrix1->iData == nullptr ||
		aSubMatrix2->iData == nullptr ||
		aSubMatrix1->iData->iData == nullptr ||
		aSubMatrix2->iData->iData == nullptr ||
		aSubMatrix1->iSize != aSubMatrix2->iSize ||
		aSubMatrix1->iData->iSize != aSubMatrix2->iData->iSize)
		return Sub_Result_p;

	Sub_Result_p->iSize = aSubMatrix1->iSize;
	Sub_Result_p->iData->iSize = aSubMatrix1->iData->iSize;

	for (size_t i = 0; i < aSubMatrix1->iData->iSize; i++) {
		for (size_t j = 0; j < aSubMatrix1->iSize; j++) {
			Sub_Result_p->iData[i].iData[j] = aSubMatrix1->iData[i].iData[j] - aSubMatrix2->iData[i].iData[j];
			std::cout << '\t';
		}
		std::cout << '\n';
	}
	return Sub_Result_p;
}