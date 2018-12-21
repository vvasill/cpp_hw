#ifndef LINALG_H
#define LINALG_H

#if !defined(MATRIX_H)
	#include "matrix.h"
#endif

double* gauss(matrix*);
double* min_res(matrix*);

#endif // LINALG_H
