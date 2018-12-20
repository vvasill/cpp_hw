#ifndef MATRIX_H
#define MATRIX_H

class matrix
{
	public:
		virtual int row() const = 0;
		virtual int col() const = 0;
		virtual double get(int, int) const = 0;
		virtual void set(int, int, int) = 0;		
		virtual void print() const = 0;
	
		//virtual int operator() (const int, const int) const = 0;
};

class plain_matrix : public matrix
{
	private:
		double** _arr;
		int _row;
		int _col;
		int test;
	public:
		plain_matrix();
		plain_matrix(int, int);
		plain_matrix(const plain_matrix&);
		~plain_matrix();		
	
		virtual int row() const;
		virtual int col() const;
		virtual double get(int, int) const;
		virtual void set(int, int, int);
		virtual void print() const;
		
		//virtual int operator() (const int, const int) const;
};

#endif // MATRIX_H
