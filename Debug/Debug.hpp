#ifndef DEBUGHPP
#define DEBUGHPP
#include <iostream>


template <typename T>
class DebugAlloc {
public:
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using referance = T&;
    using const_referance = const T&;
    using size_type = size_t;
    using difference_type = std::ptrdiff_t;
    DebugAlloc() = default;
    ~DebugAlloc() = default;
    pointer allocate(size_type n);
    void deallocate(pointer, size_type);
    template <typename ...Args>
    void construct(pointer ptr, Args&&... args);
    void destroy(pointer);
};


#include "Debug.cpp"
#endif