#ifndef LINEARCPP
#define LINEARCPP
#include "Linear.hpp"

inline size_t align(size_t p, size_t al) {
    size_t m = p % al;
    if(m != 0) {
        p += al - m;
    }
    return p;
}

template <typename T>
LinearAlloc<T>::LinearAlloc(size_t size) : size_(size), offset_(0) {
    buf_ = static_cast<unsigned char*>(operator new(sizeof(T) * size));
}

template <typename T>
LinearAlloc<T>::~LinearAlloc() {
    operator delete(buf_);
}

template <typename T>
T* LinearAlloc<T>::allocate(size_t n) {
    if(offset_ + n > size_) {
        throw std::bad_alloc();
    }
    size_t of = offset_;
    offset_ += n;
    align(offset_, alignof(T));
    T* ptr = reinterpret_cast<T*>(buf_ + offset_); 
    return ptr;
} 

template <typename T>
void LinearAlloc<T>::deallocate(T*, size_t) {}
  
template <typename T>
void LinearAlloc<T>::reset() {
    offset_ = 0;
}


#endif