#ifndef LINALG_H
#define LINALG_H

#ifndef MATRIX_H
	#include "matrix.h"
#endif

bool gauss(matrix*, matrix*);
bool min_res(matrix*, matrix*, matrix*);
double max(const matrix*);
double delta(const matrix*, const matrix*);

#endif // LINALG_H
