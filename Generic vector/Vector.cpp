#include "Vector.h"

template <typename T>

void Vector::init(T num, int index){
    if(index > capacity){
        std::cout << "Error aper";
    }
    else{
        arr[index] = num;
    }
}
void Vector::inits(T* source_arr){
    for(int i = 0;i < capacity; ++i){
        init(source_arr[i], i);
    }
}
void Vector::inits(T* source_arr, T* destination_arr){
    for(int i = 0;i < capacity; ++i){
        destination_arr[i] = source_arr[i];
    }
}
void Vector::reallocPP(){
    T* temp = new T[capacity];
    inits(arr, temp);
    delete[] arr;
    arr = new T[++capacity];
    inits(temp);
    delete[] temp;
}
void Vector::reallocate(int quantity){
    T* temp = new T[capacity];
    inits(arr, temp);
    delete[] arr;
    capacity += quantity;
    arr = new T[capacity];
    inits(temp);
    delete[] temp;
}
void Vector::swap(T* op1, T* op2){
    T temp = *op1;
    *op1 = *op2;
    *op2 = temp;
}

public:

T& Vector::operator[] (const int index) const {
    return *(arr + index);
}

Vector::Vector(){
    capacity = 4;
    arr = new T[capacity];
}
Vector::Vector(const Vector& source_arr){
    this->capacity = source_arr.capacity;
    arr = new T[capacity];
    for(int i = 0; i < capacity; ++i){
        arr[i] = source_arr[i];
    }
}
Vector::Vector(const int len){
    capacity = len;
    arr = new T[capacity];
}
Vector::Vector(T* source_arr, int len){
    capacity = len;
    arr = new T[capacity];
    inits(source_arr);
}
Vector::~Vector(){
    delete[] arr;
}
void Vector::print(){
    for(int i = 0; i < capacity; ++i){
        std::cout << arr[i] << ' ';
    }
}
void Vector::pushBack(const T elem){
    reallocPP();
    arr[capacity - 1] = elem;
}
void Vector::pushBack(const T elem, int index){
    reallocPP();
    for(int i = capacity; i > index; --i){
        swap(arr + i, arr + i - 1);
    }
    arr[index] = elem;
}
void Vector::Initialize(int num){
    for(int i = 0; i < capacity; ++i){
        arr[i] = num;
    }
}
