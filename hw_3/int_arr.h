#ifndef INT_ARR_H
#define INT_ARR_H

class int_arr
{
	private:
		int *_arr;
		int _size;
		int_arr();
	public:
		int_arr( int size );
		~int_arr();	

		//int operator[] (const int) const;
		int_arr& operator+= (const int_arr& arr);
		friend int_arr& operator+ (int_arr lhs, const int_arr& rhs);
	
		int_arr sum(int_arr* arr);
		int size();
		void init( int min, int max );	
		void print_arr();
		void swap(int &a, int &b);
		bool check_size();
		void increase_size( int inc );
		void sort_arr();
	
};

#endif
