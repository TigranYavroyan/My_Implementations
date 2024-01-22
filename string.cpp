#include <iostream>

class String {
public:
    String () : m_size{0}, m_capacity{0}, m_string{nullptr} { std::cout << "default ctor call" << std::endl; }
    String (const char *s) : m_size{0}, m_capacity{_strlen(s)}, m_string{new char[m_capacity]} {
        while (m_size < m_capacity) {
            m_string[m_size] = s[m_size];
            ++m_size;
        }
        std::cout << "params ctor call" << std::endl;
    }
    String (const String& other) : m_size{0}, m_capacity{other.m_capacity}, m_string{new char[m_capacity]} {
        while (m_size < m_capacity) {
            m_string[m_size] = other.m_string[m_size];
            ++m_size;
        }
        std::cout << "copy ctor call" << std::endl;
    }
   String (String&& rvalue) : m_capacity{rvalue.m_capacity}, m_size{rvalue.m_size}, m_string{rvalue.m_string} {
        rvalue.m_string = nullptr;
        rvalue.m_capacity = 0;
        rvalue.m_size = 0;
        std::cout << "move ctor call" << std::endl;
    }
    ~String () {
        delete[] m_string;
    }
public:
    void printString () const {
        std::cout << m_string << std::endl;
    }

    void add(const String& other) {
        _reallocateSummarySize(other);
        for (int i = m_size, j = 0; j < other.m_size; ++i, ++j) {
            m_string[i] = other.m_string[j];
        }
    }

    const char& operator[] (size_t i) const {
        return m_string[i];
    }

    char& operator[] (size_t i) {
        return m_string[i];
    }

    String& operator= (const String& other) {
        if (this == &other) {
            std::cout << "copy assign call" << std::endl;
            return *this;
        }
        _reallocateSize(other);
        for (int i = 0; i < m_capacity; ++i) {
            m_string[i] = other.m_string[i];
        }
        std::cout << "copy assign call" << std::endl;
        return *this;
    }

    String operator+ (const String& other) {
        std::cout << "operator+ call" << std::endl;
        String s(*this);
        s.add(other);
        return s;
    }

    String cascadCheck () const {
        std::cout << "Cascad call" << std::endl;
        return *this;
    }
    const char* get_string () const {
        return m_string;
    }
    int get_size () const {
        return m_size;
    }
    friend std::istream& operator>> (std::istream& is, String& str);

private:
    int m_size;
    int m_capacity;
    char *m_string;

    void _reallocateSize(const String& other) { // catching the same capacity as other 
        m_capacity = other.m_capacity;
        m_size = other.m_size;
        delete m_string;
        m_string = new char[m_capacity];
    }

    void _reallocateSummarySize(const String& other) { // catching the summary capacity of the this and other
        m_capacity += other.m_capacity;
        char* tmp = new char[m_capacity];
        for (int i = 0; i < m_size; ++i) {
            tmp[i] = m_string[i];
        }
        delete m_string;
        m_string = tmp;
    }

    int _strlen(const char* str) {
        int count = 0;

        while (*str) {
            ++count;
            ++str;
        }

        return count;
    }

};

int strlen(const char* str) {
    int count = 0;

    while (*str) {
        ++count;
        ++str;
    }

    return count;
}

std::ostream& operator<< (std::ostream& os, const String& str) {
    return os << str.get_string();
}

std::istream& operator>> (std::istream& is, String& str) {
    char buffer[500];
    is.getline(buffer, 500);
    int size = strlen(buffer);
    if (size > 0) {
        if (size > str.get_size()) {
            delete[] str.m_string;
            str.m_string = new char[size + 1];
            str.m_capacity = size;
        }
        for (int i = 0; i < size; ++i) {
            str[i] = buffer[i];
        }
        str[size] = '\0';
        str.m_size = size;
    }
    return is;
}

int main () {
    String s1;
    std::cout << "Input the objs string: ";
    std::cin >> s1;
    std::cout << s1 << std::endl;
    return 0;
} 