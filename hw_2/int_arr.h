#ifndef INT_ARR_H
#define INT_ARR_H

class int_arr
{
	private:
		int* arr_;
		int size_;
	public:
		int_arr( int size );
		int_arr();
		~int_arr();	

		int operator[] (const int) const;
		int_arr operator+ (int_arr& arr);

		int size();
		void init( int, int );	
		void print_arr();
		void swap(int&, int&);
		bool check_size();
		void increase_size( int inc );
		void sort_arr();
	
};

#endif
