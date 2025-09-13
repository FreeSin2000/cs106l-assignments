template<typename T, T default_data>
class MyClass {
private:
    T data;
    void takeBreak();
public:
    MyClass();
    MyClass(T value);
    T getData() const;
    void setData(T value);
};

#include "class.cpp"