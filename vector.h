#ifndef OOP6_VECTOR_H
#define OOP6_VECTOR_H

#include <memory>
#include <iterator>
#include <utility>

template<class T> struct vector {

public:
    using value_type = T;
    using iterator = T *;

    iterator begin() const;

    iterator end() const;

    vector() : data(std::move(std::unique_ptr<T[]>(new T[1]))), size(0), cap(1) {};

    vector(int size) : data(std::move(std::unique_ptr<T[]>(new T[size]))), size(0), cap(size) {};

    T &operator[](int i);

    void push_back(const T &value);

    void erase(int pos);

    void resize(int NewSize);

    int get_size();

    ~vector() {};

private:
    std::unique_ptr<T[]> data;
    int size;
    int cap;
};

template<class T>
T &vector<T>::operator[](int i) {
    try{
        if (i >= size) {
            throw "ERROR: Vector size smaller";
        }
        return data[i];
    } catch(const char* f) {
        std::cout << f << "\n";
    }
}

template<class T>
void vector<T>::push_back(const T &value) {
    if (cap == size) {
        resize(size * 2);
    }
    data[size++] = value;
}

template<class T>
void vector<T>::erase(int pos) {
    std::unique_ptr<T[]> newData(new T[cap]);
    for (int i = 0; i < size; ++i) {
        if (i < pos) {
            newData[i] = data[i];
        } else if (i > pos) {
            newData[i - 1] = data[i];
        }
    }
    data = std::move(newData);
    size--;
}


template<class T>
void vector<T>::resize(int size) {
    std::unique_ptr<T[]> newData(new T[size]);
    int n = std::min(size, this->size);
    for (int i = 0; i < n; ++i) {
        newData[i] = data[i];
    }
    data = std::move(newData);
    this->size = n;
    cap = size;
}

template<class T>
int vector<T>::get_size() {
    return size;
}

template<class T>
typename vector<T>::iterator vector<T>::begin() const {
    return &data[0];
}

template<class T>
typename vector<T>::iterator vector<T>::end() const {
    return data[size];
}


#endif //OOP6_VECTOR_H
