#ifndef INT_ARR_H
#define INT_ARR_H

class int_arr
{
	private:
		int *_arr;
		int _size;
	public:
		int_arr( int size );
		int_arr();
		~int_arr();	

		int operator[] (const int) const;
		int_arr operator+ (int_arr& arr);
	
		int size();
		void init( int min, int max );	
		void print_arr();
		void swap(int &a, int &b);
		bool check_size();
		void increase_size( int inc );
		void sort_arr();
	
};

#endif
