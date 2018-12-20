#ifndef MATRIX_H
#define MATRIX_H

class matrix
{
	public:
		virtual int raw() = 0;
		virtual int col() = 0;
		virtual double get(int, int) = 0;
		virtual void set(int, int, int) = 0;		
		virtual void print() = 0;
	
		virtual int operator() (const int, const int) = 0;
};

class plain_matrix : public matrix
{
	private:
		double** _arr;
		int _raw;
		int _col;
		plain_matrix();
	public:
		plain_matrix(int, int);
		~plain_matrix();		
	
		int raw() const;
		int col() const;
		double get(int, int) const;
		void set(int, int, int);
		void print() const;
};

#endif // MATRIX_H
