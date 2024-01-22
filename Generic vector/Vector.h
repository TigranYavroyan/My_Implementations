#ifndef VECTOR_H
#define VECTOR_H

template <typename T>

class Vector {
	T* arr;
	int capacity;
	void init(T num, int index);
	void inits(T* source_arr);
	void inits(T* source_arr, T* destination_arr);
	void reallocPP();
	void reallocate(int quantity);
	void swap(T* op1, T* op2);

public:

	T& operator[] (const int index) const;

	Vector();
	Vector(const Vector& source_arr);
	Vector(const int len);
	Vector(T* source_arr, int len);
	~Vector();
	void print();
	void pushBack(const T elem);
	void pushBack(const T elem, int index);
	void Initialize(int num);
};

#endif