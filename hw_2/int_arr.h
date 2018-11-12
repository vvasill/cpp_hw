#ifndef INT_ARR_H
#define INT_ARR_H

class int_arr
{
	private:
		int* _arr;
		int _size;
		int_arr();
	public:
		int_arr( int size );
		~int_arr();	

		int size();
		void init( int, int );	
		void print_arr();
		void swap(int&, int&);
		bool check_size();
		void increase_size( int inc );
		void sort_arr();
	
};

#endif
