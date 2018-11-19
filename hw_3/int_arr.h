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

		int_arr& operator= (const int_arr arr);
		int& operator[] (const int) const;
		int_arr& operator+= (const int_arr arr);
		int_arr operator+ (const int_arr l_arr, const int_arr r_arr);
	
		int size();
		int get(int i);
		void set(int i, int num);
		void init(int min, int max);	
		void print_arr();
		void swap(int &a, int &b);
		bool check_size();
		void increase_size(int inc);
		void sort_arr();
		int_arr sum(const int_arr s_arr);
	
};

#endif
