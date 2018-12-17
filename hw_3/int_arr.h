#ifndef INT_ARR_H
#define INT_ARR_H

class int_arr
{
	private:
		int* _arr;
		int _size;
	public:
		int_arr();
		int_arr(int);
		int_arr(const int_arr &);
		~int_arr();	

		int size();
		void set(int, int);
		int get(int);
		void init(int, int);	
		void print();
		void swap(int&, int&);
		bool check_size();
		void increase_size(int);
		void sort();

		int_arr& operator= (const int_arr&);
		int operator[] (const int) const;
		int_arr& operator+= (const int_arr&);
		int_arr& operator-= (const int_arr&);
		friend int_arr operator+ (const int_arr, const int_arr);
		int_arr operator- (const int_arr&);
		int_arr operator* (const int_arr&);	
		int_arr operator& (const int_arr);
};

#endif // INT_ARR_H
