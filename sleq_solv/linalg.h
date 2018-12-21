#ifndef LINALG_H
#define LINALG_H

#if !defined(MATRIX_H)
	#include "matrix.h"
#endif

matrix* gauss(matrix*);
matrix* min_res(matrix*);

#endif // LINALG_H
