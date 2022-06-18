#include <iostream>

class String{
private:
    char* m_buffer;
    int m_size;
public:
    String ( const char * s){
        std::cout << "Constructor String () running " << std::endl;
        m_size = strlen(s);
        m_buffer = new char[m_size + 1];
        memcpy(m_buffer, s, m_size);
        m_buffer[m_size] = '\0';

    }

    String ( const String& s) {
        std::cout << "Deep Copy Constructor String ( const String& s) running " << std::endl;
        m_size = s.m_size;
        m_buffer = new char[m_size + 1];
        memcpy(m_buffer, s.m_buffer, m_size);
        m_buffer[m_size] = '\0';
    }

    friend std::ostream& operator<<(std::ostream& os, const String& s);

    ~String(){
        std::cout << "Destructor String () running " << std::endl;

        //Print buffer address
        std::cout << "Deleting " << static_cast<void *> (m_buffer) << std::endl;
        delete[] m_buffer;
    }
};
std::ostream & operator<<(std::ostream & os, const String & s){
    os << s.m_buffer;
    return os;
}

void printString ( const String& str){
    String s = str;
    std::cout << str << std::endl;

}

int main () {
    String s("Hello World");
    String s2 = s;

    //std::cout << s << std::endl;
    printString(s);


    return 0;
}
