#include "Vector.h"
#include "c:\GitHub\BPC-PPC\checker\check.h"

using std::cerr;

int Add(TVector aAddVector1, TVector aAddVector2, TVector* aAdd_Result_ptr) {
	if (aAdd_Result_ptr == nullptr ||
		aAddVector1.iData == nullptr ||
		aAddVector2.iData == nullptr ||
		aAddVector1.iSize != aAddVector2.iSize ||
		aAddVector1.iSize != aAdd_Result_ptr->iSize)
		return 1;

	for (size_t i = 0; i < aAddVector1.iSize; i++)
		aAdd_Result_ptr->iData[i] = aAddVector1.iData[i] + aAddVector2.iData[i];
	return 0;
}

TVector* Sub(TVector* aSubVector1, TVector* aSubVector2) {
	TVector* Sub_Result_p = (TVector*)calloc(1, sizeof(TVector));
	if (Sub_Result_p == nullptr) {
		cerr << "Allocation failed!" << '\n';			// std::endl vlozi "\n" (line feed)
		free(Sub_Result_p);
		exit(1);
	}
	if (aSubVector1 == nullptr ||
		aSubVector2 == nullptr ||
		aSubVector1->iData == nullptr ||
		aSubVector2->iData == nullptr ||
		aSubVector1->iSize != aSubVector2->iSize)
		return Sub_Result_p;

	Sub_Result_p->iSize = aSubVector1->iSize;

	for (size_t j = 0; j < aSubVector1->iSize; j++)
		Sub_Result_p->iData[j] = aSubVector1->iData[j] - aSubVector2->iData[j];
	return Sub_Result_p;
}