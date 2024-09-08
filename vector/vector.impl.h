#include "vector.h"

namespace myStl {

template <typename T, typename Allocator>
vector<T, Allocator>::vector(const Allocator& alloc)
    : alloc_{alloc}
    , size_{0}
    , capacity_{0}
    , arr_{nullptr}
{}

template<typename T, typename Allocator>
vector<T, Allocator>::vector(size_t n, const T& value, const Allocator &alloc)
    : alloc_{alloc}
    , size_{n}
    , capacity_{n}
    , arr_{alloc_.allocate(size_)}
{
    for (int i = 0; i < size_; ++i) {
        //new (arr_ + i) T(value);
        alloc_.construct(arr_ + i, value);
    }
}

template <typename T, typename Allocator>
vector<T, Allocator>::vector(const std::initializer_list<T>& il, const Allocator& alloc)
    : alloc_{alloc}
    , size_{il.size()}
    , capacity_{il.size()}
    , arr_{alloc_.allocate(size_)}
{
    int i = 0;
    for (auto iter = il.begin(); iter != il.end(); ++iter) {
        alloc_.construct(arr_ + i++, *iter);
    }
}

template <typename T, typename Allocator>
void vector<T, Allocator>::reserve(size_t n) {
    if (n <= capacity_) return;
    T *newarr = alloc_.allocate(n);

    for (size_t i = 0; i < size_; ++i) 	{
        //new (newarr + i) T(arr_[i]);
        alloc_.construct(newarr + i, arr_[i]);
        //(arr_ + i)->~T();
        alloc_.destroy(arr_ + i);
    }

    alloc_.deallocate(arr_, size_);
    arr_ = newarr;
    capacity_ = n;
}

template <typename T, typename Allocator>
void vector<T, Allocator>::push_back(const T& value) {
    if (size_ >= capacity_) {
        size_t newCapacity = (capacity_ == 0) ? 1 : (size_ * 2);
        reserve(newCapacity);
    }
    alloc_.construct(arr_ + size_, value);
    ++size_;
}

template <typename T, typename Allocator>
void vector<T, Allocator>::pop_back() {
    alloc_.destroy(arr_ + size_);
    --size_;
}

template <typename T, typename Allocator>
const T &vector<T, Allocator>::operator [](size_t index) const {
    return arr_[index];
}

template <typename T, typename Allocator>
T& vector<T, Allocator>::operator[](size_t index) {
    return arr_[index];
}

template<typename T, typename Allocator>
void vector<T, Allocator>::clear() {
    for(size_t i = 0; i < size_; ++i) {
        //(arr_ + i)->~T();
        alloc_.destroy(arr_ + i);
    }
    alloc_.deallocate(arr_, size_);
    size_ = 0;
}

template<typename T, typename Allocator>
vector<T, Allocator>::~vector() {
    if (empty()) {
        clear();
    }
}

}
