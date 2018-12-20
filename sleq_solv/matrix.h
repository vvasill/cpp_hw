#ifndef MATRIX_H
#define MATRIX_H

class matrix
{
	protected:
		double** _arr;
		matrix();
	public:
		virtual ~matrix();	

		void print();
		virtual int raw() = 0;
		virtual double get() = 0;
		virtual void set() = 0;		
};

class double_matrix : public matrix
{
	private:
		int _raw;
		int _col;
	public:
		double_matrix(int, int);
		~double_matrix();		
	
		int raw() override;
		double get() override;
		void set() override;
};

class double_vec : public matrix
{
	private:
		int _len;
	public:
		double_vec(int);	
		~double_vec();		
		
		int raw() override;
		double get() override;
		void set() override;
};

#endif // MATRIX_H
