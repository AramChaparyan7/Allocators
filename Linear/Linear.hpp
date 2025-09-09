#ifndef LINEARHPP
#define LINEARHPP
#include <iostream>


template <typename T>
class LinearAlloc {
private:
    size_t size_;
    size_t offset_;
    unsigned char* buf_;
public:
    using value_type = T;
    LinearAlloc(size_t size = 1024);
    ~LinearAlloc();
    T* allocate(size_t n);
    void deallocate(T*, size_t);
    void reset();
};

inline size_t align(size_t p, size_t al);



#include "Linear.cpp"
#endif