template<typename T, T default_data>
MyClass<T, default_data>::MyClass() {
    data = default_data;
}

template<typename T, T default_data>
MyClass<T, default_data>::MyClass(T value) : data(value) {
}

template<typename T, T default_data>
T MyClass<T, default_data>::getData() const {
    return data;
}

template<typename T, T default_data>
void MyClass<T, default_data>::setData(T value) {
    data = value;
}

template<typename T, T default_data>
void MyClass<T, default_data>::takeBreak() {

}