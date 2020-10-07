#include <cstdlib>
#include <iostream>
#include "Vector.h"
#include "Matrix.h"
#include "c:\GitHub\BPC-PPC\checker\check.h"		// Checker musi byt jako posledni!

//Choose one of them:
//#define VECTOR
#define MATRIX

using std::cout;		// Dale neni treba psat std::cout, staci cout.
using std::cerr;
// using namespace std;		<-- SPATNE!

int main()
{
#ifdef MATRIX
	// Set and Get test:
	TMatrix matrix1 = { Y, { X, { 0 } } };
	TMatrix matrix2 = { Y, { X, { 0 } } };
	TMatrix* matrix3 = (TMatrix*)calloc(1, sizeof(TMatrix));

	if (matrix3 == nullptr) {
		cout << "Allocation failed!" << std::endl;		// std::endl vlozi "\n" (line feed) a zaroven cisti buffer, ze ktereho se cte
		exit(1);
	}
	matrix3->iSize = Y;
	matrix3->iData->iSize = X;

	for (size_t i = 0; i < Y; i++) {
		for (size_t j = 0; j < X; j++) {
			if ((Set(&matrix1, j, i, (double)i)) == 1)
				return 1;
		}
	}

	for (size_t i = 0; i < Y; i++) {
		for (size_t j = 0; j < X; j++) {
			if ((Set(&matrix2, j, i, 10 - (2 * (double)j - (double)i))) == 1)
				return 1;
		}
	}

	for (size_t i = 0; i < Y; i++) {
		for (size_t j = 0; j < X; j++) {
			if ((Set(matrix3, j, i, 3 + (double)i * 5)) == 1)
				return 1;
		}
	}

	cout << "matrix1: " << '\n';
	Print(&matrix1);
	cout << "matrix2: " << '\n';
	Print(&matrix2);
	cout << "matrix3: " << '\n';
	Print(matrix3);
	cout << '\n';

	// Getting a value from vector1 (an EXCEPTION example):		Nejdrive dochazi ke "throw" v miste, kde muze nastat chyba, nasleduje "try", kde -----DOPSAT
	size_t Row_Index, Column_Index;
	cout << "Please, enter the Row_Index (between 0 and " << (X - 1) << ") and the Column_Index (between 0 and " << (Y - 1) << ") of a wanted value." << '\n' << '\n';
	cout << "Row_Index: " << '\n';
	std::cin >> Row_Index;				// C: scanf("%zu", &Row_Index);
	cout << '\n';
	cout << "Column_Index: " << '\n';
	std::cin >> Column_Index;
	cout << '\n';

	try {
		double got_value = Get(&matrix1, Row_Index, Column_Index);
		cout << "The value of matrix1 at Row_Index " << Row_Index << " and Column_Index " << Column_Index << " is: " << got_value;
	}
	catch (const std::out_of_range exception01) {
		cerr << exception01.what() << '\n';		// exception01.what() -> obsah objektu out_of_range
	}

	// Add and Sub test:
	TMatrix* Add_Result_ptr = (TMatrix*)calloc(1, sizeof(TMatrix));
	if (Add_Result_ptr == nullptr) {
		cerr << "Allocation failed!" << '\n';
		exit(1);
	}

	Add_Result_ptr->iSize = Y;
	Add_Result_ptr->iData->iSize = X;
	if ((Add(matrix1, matrix2, Add_Result_ptr)) == 1) {		// Do funkce vkladame cele struktury, nikoli pouze adresy struktur -> pametove narocne -> lepsi reseni
		cerr << "Addition failed!" << '\n';		// ve funkci Sub() pomoci pointeru
		free(Add_Result_ptr);
		exit(1);
	}
	cout << "Addition of two matrices: matrix1 and matrix2." << '\n';
	Print(Add_Result_ptr);
	free(Add_Result_ptr);

	TMatrix* Sub_Result_ptr = nullptr;

	Sub_Result_ptr = Sub(&matrix1, matrix3);
	cout << "Subtraction of two matrices: matrix1 and matrix3." << '\n';
	Print(Sub_Result_ptr);
	free(Sub_Result_ptr);

	free(matrix3);
#endif // MATRIX

#ifdef VECTOR
	// Set and Get test:
	TVector vector = { Y, { 0 } };
	TVector vector1 = { X, { 0 } };
	TVector vector2 = { X, { 0 } };
	TVector* vector3 = (TVector*)calloc(1, sizeof(TVector));

	if (vector3 == nullptr) {
		cout << "Allocation failed!" << std::endl;		// std::endl vlozi "\n" (line feed) a zaroven cisti buffer, ze ktereho se cte
		exit(1);
	}
	vector3->iSize = X;

	for (size_t h = 0; h < Y; h++) {
		if ((Set(&vector, h, (double)(2 * h))) == 1)
			return 1;
	}
	for (size_t i = 0; i < X; i++) {
		if ((Set(&vector1, i, (double)i)) == 1)
			return 1;
	}
	for (size_t j = 0; j < X; j++) {
		Set(&vector2, j, (double)(j + 10));
	}
	for (size_t j = 0; j < X; j++) {
		Set(vector3, j, (double)(3 * j + 31));
	}

	cout << "vector: " << '\n';
	Print(&vector);
	cout << "vector1: " << '\n';
	Print(&vector1);
	cout << "vector2: " << '\n';
	Print(&vector2);
	cout << "vector3: " << '\n';
	Print(vector3);
	cout << "matrix3: " << '\n';

	// Getting a value from vector1 (an EXCEPTION example):
	size_t position;
	cout << "Please, enter the position (between 0 and " << (X - 1) << ") of a wanted value." << '\n';
	std::cin >> position;		// C: scanf("%zu", &position);

	try {
		double got_value = Get(&vector1, position);
		cout << "The value of vector1 at position " << position << " is: " << got_value << '\n' << '\n';
	}
	catch (const std::out_of_range exception01) {
		cerr << exception01.what() << '\n';		// exception01.what() -> obsah objektu out_of_range
	}

	// Add and Sub test:
	TVector* Add_Result_ptr = (TVector*)calloc(1, sizeof(TVector));
	if (Add_Result_ptr == nullptr) {
		cerr << "Allocation failed!" << '\n';
		exit(1);
	}

	Add_Result_ptr->iSize = X;
	if ((Add(vector1, vector2, Add_Result_ptr)) == 1) {		// Do funkce vkladame cele struktury, nikoli pouze adresy struktur -> pametove narocne -> lepsi reseni
		cerr << "Addition failed!" << '\n';		// ve funkci Sub() pomoci pointeru
		free(Add_Result_ptr);
		exit(1);
	}
	cout << "Addition of two vectors: vector1 and vector2." << '\n';
	Print(Add_Result_ptr);
	free(Add_Result_ptr);

	TVector* Sub_Result_ptr = nullptr;

	Sub_Result_ptr = Sub(&vector1, vector3);
	cout << "Subtraction of two vectors: vector1 and vector3." << '\n';
	Print(Sub_Result_ptr);
	free(Sub_Result_ptr);

	free(vector3);
#endif // VECTOR
}