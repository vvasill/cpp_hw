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

		int size() const;
		void set(int, int);
		int get(int) const;
		void init(int, int);	
		void print() const;
		void swap(int&, int&);
		bool check_size(int) const;
		void increase_size(int);
		void sort();

		int_arr& operator= (const int_arr&);
		int operator[] (const int) const;
		int& operator[] (const int);
		int_arr& operator+= (const int_arr&);
		int_arr& operator-= (const int_arr&);
		friend int_arr operator+ (const int_arr&, const int_arr&);
		int_arr operator- (const int_arr&) const;
		int operator* (const int_arr&) const;	
		int_arr operator& (const int_arr&) const;
};

#endif // INT_ARR_H
