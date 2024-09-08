#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <initializer_list>

namespace myStl {

template<typename T, typename Allocator = std::allocator<T>>
class vector
{
public:
    vector(const Allocator& alloc = Allocator());
    vector(size_t n, const T& value = T(), const Allocator& alloc = Allocator());
    vector(const std::initializer_list<T>& il, const Allocator& alloc = Allocator());
    void reserve(size_t n);
    void push_back(const T& value);
    void pop_back();
    void clear();
    size_t size() const {
        return size_;
    }
    size_t capacity() const {
        return capacity_;
    }
    bool empty() {
        return size_ == 0;
    }
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    ~vector();
private:
    Allocator alloc_;
    size_t size_;
    size_t capacity_;
    T* arr_;
};

}

#include "vector.impl.h"

#endif // VECTOR_H
