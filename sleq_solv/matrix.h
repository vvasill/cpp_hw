#ifndef MATRIX_H
#define MATRIX_H

class matrix
{
	protected:
		matrix();
	public:
		virtual ~matrix();	

		void print();
		virtual int raw() = 0;
		virtual int col() = 0;
		virtual double get(int, int) = 0;
		virtual void set(int, int) = 0;		
};

class double_matrix : public matrix
{
	private:
		double** _arr;
		int _raw;
		int _col;
	public:
		double_matrix(int, int);
		~double_matrix();		
	
		int raw() override;
		double get() override;
		void set() override;
};

#endif // MATRIX_H
