#ifndef LINEARHPP
#define LINEARHPP
#include <iostream>


template <typename T>
class LinearAlloc {
private:
    size_t size_;
    size_t offset_;
    void* buf_;
public:
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using referance = T&;
    using const_referance = const T&;
    using size_type = size_t;
    using difference_type = std::ptrdiff_t;
    size_type align(size_type p, size_type al);
    LinearAlloc(size_type size = 1024);
    ~LinearAlloc();
    pointer allocate(size_type n);
    void deallocate(pointer, size_type);
    template <typename ...Args>
    void construct(pointer ptr, Args&&... args);
    void destroy(pointer);
    void reset();
};


#include "Linear.cpp"
#endif