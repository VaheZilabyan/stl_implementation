#ifndef ALLOCATOR_H
#define ALLOCATOR_H

namespace myVectorAllocator {

template<typename T>
class allocator
{
public:
    static T* allocate(size_t n) {
        return static_cast<T*>(::operator new(n * sizeof(T)));
        //return static_cast<T*>(malloc(n * sizeof(T)));
    }
    static void deallocate(T *ptr, size_t) {
        ::operator delete((void*)ptr);
    }
    template<typename... Args>
    static void construct(T *ptr, const Args&... args) {
        new (ptr) T(args...);
    }
    static void destroy(T *ptr) {
        ptr->~T();
    }
};

}


#endif // ALLOCATOR_H
