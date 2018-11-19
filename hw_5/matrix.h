#ifndef MATRIX_H
#define MATRIX_H

class matrix
{
	private:
		int *_m;
		int _row;
		int _col;
	public:
		matrix( int row, int col );
		matrix();
		~matrix();
		
		int det();	
	
};

#endif
