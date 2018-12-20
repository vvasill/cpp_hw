#ifndef LINALG_H
#define LINALG_H

#if !defined(MATRIX_H)
	#include "matrix.h"
#endif

double* gauss(const matrix&);
double* min_res(const matrix&);

#endif // LINALG_H
