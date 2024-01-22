#include <iostream>
#include <ctime>

void printArr(int* arr, int len){
    for(int i = 0; i < len; ++i){
        std::cout << arr[i] << ' ';
    }
    std::cout.put('\n');
}

class Vector{
public:

    Vector() : m_capacity{0} , m_size{0} , m_arr{new int[m_capacity]} {}

    Vector(int size): m_size{0} {
        m_capacity = size;
        m_arr = new int [m_capacity];
    }

    Vector(int* arr, int len) {
        m_capacity = len;
        m_size = len;
        m_arr = new int[m_capacity];
        copy(arr);
    }

    Vector(Vector&& rvalue){
        m_capacity = rvalue.m_capacity;
        m_size = rvalue.m_size;
        m_arr = rvalue.m_arr;
        rvalue.m_arr = nullptr;
    }

    Vector(const Vector& oth) {
        m_capacity = oth.m_capacity;
        m_size = oth.m_size;
        m_arr = new int[m_capacity];
        copy(oth.m_arr);
    }

    ~Vector() {
        delete[] m_arr;
    }

public:

    int& operator[] (const int index) const {
        return *(m_arr + index);
    }

    Vector operator+ (const Vector& rhs) const {
        Vector res;
        res.m_capacity = m_capacity + rhs.m_capacity;
        res.m_size = m_size + rhs.m_size;
        res.m_arr = new int[res.m_capacity];

        int count1{0};
        while(count1 < m_size) {
            res.m_arr[count1] = m_arr[count1];
            ++count1;
        }

        int count2{0};
        while(count2 < rhs.m_size) {
            res.m_arr[count1] = rhs.m_arr[count2];
            ++count1;
            ++count2;
        }
        return res;
    }

    Vector& operator= (const Vector& oth) {
        if(this == &oth){
            return *this;
        }
        delete[] m_arr;
        m_capacity = oth.m_capacity;
        m_size = oth.m_size;
        m_arr = new int[m_capacity];
        copy(oth.m_arr);
        return *this;
    }

    void operator+= (const Vector& oth){
        if(this == &oth){
            throw std::invalid_argument("Քեզ լավ օր");
        }
        int* tmp = new int[m_capacity + oth.m_capacity];

        int count = 0;
        while(count < m_size){
            tmp[count] = m_arr[count];
            ++count;
        }

        delete[] m_arr;

        for(int i = 0; i < oth.m_size; ++i, ++count){
            tmp[count] = oth.m_arr[i];
        }

        m_capacity = m_capacity + oth.m_capacity;
        m_size = m_size + oth.m_size;
        m_arr = tmp;
        tmp = nullptr;
    }

    void sortByIncr(){
        bubbleSort();
    }

    int find(int num){
        int index = binarySearch(num);
        return index;
    }
    
    void print() const {
        for(int i = 0; i < m_size; ++i){
            std::cout << m_arr[i] << ' ';
        }
        std::cout.put('\n');
    }

    void pushBack(int num){
        if(m_size == m_capacity){
            reallocateX2();
        }
        m_arr[m_size++] = num;
    }

    void pushFront(int num){
        if(m_size == m_capacity)
            reallocateX2();
        pushToRight();
        m_arr[0] = num;
    }

    void push(int num, int index){
        if(index > m_size)
            throw std::invalid_argument("Ախպերս, քո թերացումնա");
        if(m_size == m_capacity)
            reallocateX2();
        pushToRight(index - 1);
        m_arr[index - 1] = num;
    }

    void printSizes() const {
        std::cout << m_size << std::endl;
        std::cout << m_capacity << std::endl;
    }

private:
    int m_capacity;
    int m_size;
    int* m_arr;

    void reallocateX2() {
        m_capacity = (m_capacity) ? m_capacity *= 2 : 1;
        int* tmp  = new int[m_capacity];
        for(int i = 0; i < m_size; ++i){
            tmp[i] = m_arr[i];
        }
        delete[] m_arr;
        m_arr = tmp;
    }

    void reallocateExactSize(int size){
        m_capacity = size;
        int* tmp = new int[m_capacity];
        for(int i = 0; i < m_size; ++i){
            tmp[i] = m_arr[i];
        }
        delete[] m_arr;
        m_arr = tmp;
    }

    void copy(int* source){
        for(int i = 0; i < m_size; ++i){
            m_arr[i] = source[i];
        }
    }

    void copy(const Vector& oth){
        for(int i = 0; i < m_size; ++i){
            m_arr[i] = oth.m_arr[i];
        }
    }

    void pushToRight(){
        ++m_size;
        for(int i = m_size - 1; i > 0; --i){
            swap(m_arr + i, m_arr + i - 1);
        }
    }

    void pushToRight(int index){
        ++m_size;
        for(int i = m_size - 1; i > index; --i){
            swap(m_arr + i, m_arr + i - 1);
        }
    }

    void swap(int* op1, int* op2){
        int tmp = *op1;
        *op1 = *op2;
        *op2 = tmp;
    }

    int binarySearch(int target){
        int low = 0;
        int high = m_size - 1;
        int middle =  0;
        while(low <= high){
            middle = low + (high - low) / 2;
            if(target == m_arr[middle])
                return middle;
            else if(target > m_arr[middle])
                low = middle + 1;
            else
                high = middle - 1;
        }
        return -1;
    }

    void bubbleSort(){
        for(int i = 0; i < m_size - 1; ++i){
            for(int j = 0; j < m_size - i - 1; ++j){
                if(m_arr[j] > m_arr[j + 1])
                    swap(m_arr + j, m_arr + j + 1);
            }
        }
    }
};



int main() {
    //srand(time(0));

    int len = 10;
    int arr[len];
    for(int i = 0; i < len; ++i){
        arr[i] = rand() % 41 - 20;
    }
    Vector v(arr, len);
    v.print();
    v.sortByIncr();
    v.print();
    int index = v.find(12);
    std::cout << "The v[" << index << "] is a " << v[index] << std::endl;
    return 0;
}