#include <iostream>
#include <ctime>

template <typename T>

class Vector {
	T* arr;
	int capacity;

	void init(T num, int index){
		if(index > capacity){
			std::cout << "Error aper";
		}
		else{
			arr[index] = num;
		}
	}
	void inits(T* source_arr){
		for(int i = 0;i < capacity; ++i){
			init(source_arr[i], i);
		}
	}
	void inits(T* source_arr, T* destination_arr){
		for(int i = 0;i < capacity; ++i){
			destination_arr[i] = source_arr[i];
		}
	}
	void reallocPP(){
		T* temp = new T[capacity];
		inits(arr, temp);
		delete[] arr;
		arr = new T[++capacity];
		inits(temp);
		delete[] temp;
	}
	void reallocate(int quantity){
		T* temp = new T[capacity];
		inits(arr, temp);
		delete[] arr;
		capacity += quantity;
		arr = new T[capacity];
		inits(temp);
		delete[] temp;
	}
	void swap(T* op1, T* op2){
		T temp = *op1;
		*op1 = *op2;
		*op2 = temp;
	}

public:

	T& operator[] (const int index) const {
		return *(arr + index);
	}

	Vector(){
		capacity = 4;
		arr = new T[capacity];
	}
	Vector(const Vector& source_arr){
		this->capacity = source_arr.capacity;
		arr = new T[capacity];
		for(int i = 0; i < capacity; ++i){
			arr[i] = source_arr[i];
		}
	}
	Vector(const int len){
		capacity = len;
		arr = new T[capacity];
	}
	Vector(T* source_arr, int len){
		capacity = len;
		arr = new T[capacity];
		inits(source_arr);
	}
	~Vector(){
		delete[] arr;
	}
	void print(){
		for(int i = 0; i < capacity; ++i){
			std::cout << arr[i] << ' ';
		}
	}
	void pushBack(const T elem){
		reallocPP();
		arr[capacity - 1] = elem;
	}
	void pushBack(const T elem, int index){
		reallocPP();
		for(int i = capacity; i > index; --i){
			swap(arr + i, arr + i - 1);
		}
		arr[index] = elem;
	}
	void Initialize(int num){
		for(int i = 0; i < capacity; ++i){
			arr[i] = num;
		}
	}
};

int main() {

	srand(time(0));

	const int len = 10;
	int num = -23470;
	
	int arr[len];

	for(int i = 0; i < len; ++i){
		arr[i] = rand() % 41 - 20;
		std::cout << arr[i] << ' ';
	}
	std::cout.put('\n');
	// std::cout.put('\n');
	// Vector<int> vector(arr, len);
	// vector.pushBack(num * 3);
	// vector.pushBack(num, 2);

	// vector.print();
	Vector<int> valod(arr, len);
	Vector<int> mukuch(10);
	mukuch.Initialize(10);
	mukuch.print();

	return 0;
}
