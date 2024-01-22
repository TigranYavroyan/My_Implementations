#include <iostream>

class String{
public:
    String() {
        m_capacity = 10;
        m_string = new char[m_capacity + 1];
    }
    String(char* arr){
        m_capacity = strlen(arr);
        m_string = new char[m_capacity];
        for(int i = 0; arr[i] != '\0'; ++i){
            m_string[i] = arr[i];
        }
    }
    String(const char* text){
        m_capacity = strlen(text);
        m_string = new char[m_capacity];
        for(int i = 0; text[i] != '\0'; ++i){
            m_string[i] = text[i];
        }
    } 
    String(const String& string){
        m_capacity = string.m_capacity;
        m_string = new char[m_capacity];
        for(int i = 0; i < m_capacity; ++i){
            m_string[i] = string.m_string[i];
        }
    }
    ~String() {
        delete m_string;
    }

public:

    char& operator[] (const int index) const {
        return *(m_string + index);
    }

    void operator= (const String& string) {
        if(string.m_capacity > m_capacity)
            realocateTillLen(string);
        for(int i = 0; i < m_capacity; ++i){
            m_string[i] = string.m_string[i];
        }
    }

    void operator= (const char* text) {
        if(strlen(text) > m_capacity)
            realocateTillLen(text);
        for(int i = 0; i < m_capacity; ++i){
            m_string[i] = text[i];
        }
    }

    const char* operator+ (const String& string) {
        int start = m_capacity;
        realocateExactSize(strlen(string));
        for(int i = 0; string.m_string[i] != '\0'; ++i, ++start){
            m_string[start] = string.m_string[i];
        }
        return m_string;
    }

    bool findWord(const char* word){
        int count = 0;
        bool flag = true;
        for(int i = 0; m_string[i] != '\0'; ++i){
            if((word[count] == '\0' && m_string[i] == ' ' && flag) || (word[count + 1] == '\0' && m_string[i + 1] == '\0' && flag && word[count] == m_string[i])){
                return true;
            }
            if(m_string[i] == word[count]){
                ++count;
                continue;
            }
            else{
                flag = false;
            }
            if(m_string[i] == ' '){
                flag = true;
                count = 0;
            }
        }
        return false;
    }

    bool findWord(const String& str){
        int count = 0;
        bool flag = true;
        for(int i = 0; m_string[i] != '\0'; ++i){
            if((str.m_string[count] == '\0' && m_string[i] == ' ' && flag) || (str.m_string[count + 1] == '\0' && m_string[i + 1] == '\0' && flag && str.m_string[count] == m_string[i])){
                return true;
            }
            if(m_string[i] == str.m_string[count]){
                ++count;
                continue;
            }
            else{
                flag = false;
            }
            if(m_string[i] == ' '){
                flag = true;
                count = 0;
            }
        }
        return false;
    }

    void strcat(const char* source){
        int start = m_capacity;
        realocateExactSize(strlen(source));
        for(int i = 0; source[i] != '\0'; ++i, ++start){
            m_string[start] = source[i];
        }
    }

    void print() const{
        std::cout << m_string << std::endl;
    }

    int strlen() const{
        return m_capacity;
    }

    double toDouble() const{

        double num = 0;
        int count = 0;
        int count2 = 0;
        bool flag = true;

        for(int i = 0; m_string[i] != '\0'; ++i){
            if(m_string[i] == '.'){
                flag = false;
                break;
            }
        }

        if(flag){
            return toNum();
        }

        for(int i = 0; m_string[i] != '\0'; ++i){
            if((m_string[i] >= '0' && m_string[i] <= '9') || m_string[i] == '.')
                continue;
            else
                throw std::invalid_argument("Can't convert to double");
        }

        while(m_string[count + 1] != '.'){
            ++count;
        }
        count2 = count + 2;

        for(int i = 0; count >= 0; ++i, --count){
            num += (m_string[i] - '0') * power(10, count);
        }
        for(int i = 1; m_string[count2] != '\0'; ++i, ++count2){
            num += static_cast <double> ((m_string[count2] - '0')) / power(10, i);
        }

        return num;
    }

    int toNum() const{
        int num = 0;
        int count = 0;
        for(int i = m_capacity - 1; i >= 0; --i){
            if(count > 8)
                throw std::invalid_argument("Too big number");
            else if(m_string[count] >= '0' && m_string[count] <= '9'){
                num += (m_string[count] - '0') * power(10, i);
                ++count;
            }
            else
                throw std::invalid_argument("Can't convert to num");
        }
        return num;
    }

private:
    int m_capacity;
    char* m_string;

    void dublicate(char* source, char* destination){
        for(int i = 0; source[i] != '\0'; ++i){
            destination[i] = source[i];
        }
    }

    void realocate(){
        char* temp = new char[m_capacity];
        dublicate(m_string, temp);
        delete m_string;
        m_capacity *= 2;
        m_string = new char[m_capacity + 1];
        dublicate(temp, m_string);
        delete temp;
    }

    void realocateTillLen(const char* source){
        while(m_capacity < strlen(source)){
            realocate();
        }
    }

    void realocateTillLen(const String& string){
        while(m_capacity < string.m_capacity){
            realocate();
        }
    }
    void realocateExactSize(int size){
        char* temp = new char[m_capacity];
        dublicate(m_string, temp);
        delete m_string;
        m_capacity = m_capacity + size;
        m_string = new char[m_capacity];
        dublicate(temp, m_string);
        delete temp;
    }

    void copy(char* source) const {
        for(int i = 0; i < strlen(source); ++i){
            m_string[i] = source[i];
        }
    }

    void copy(const char* source) const {
        for(int i = 0; i < strlen(source); ++i){ 
            m_string[i] = source[i];
        }
    }

    int power(int num, int degree) const{
        int res = 1;
        for(int i = 0; i < degree; ++i){
            res *= num;
        }
        return res;
    }

    int strlen(char* arr) const{
        int count = 0;
        while(arr[count] != '\0'){
            ++count;
        }
        return count;
    }

    int strlen(const char* text) const{
        int count = 0;
        while(text[count] != '\0'){
            ++count;
        }
        return count;
    }

    int strlen(const String& text) const{
        int count = 0;
        while(text.m_string[count] != '\0'){
            ++count;
        }
        return count;
    }
};

int main() {

    String str = "Hello aper jan";
    String str2("");
    char name[] = {"aper"};
    bool check = str.findWord(name);
    (check) ? std::cout << "The word is found" << std::endl : std::cout << "The word isn't found" << std::endl;
    

    return 0;
}