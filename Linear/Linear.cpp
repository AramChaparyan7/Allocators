#ifndef LINEARCPP
#define LINEARCPP
#include "Linear.hpp"

template <typename T>
size_t LinearAlloc<T>::align(size_type p, size_type al) {
    size_t m = p % al;
    if(m != 0) {
        p += al - m;
    }
    return p;
}

template <typename T>
LinearAlloc<T>::LinearAlloc(size_t size) : size_(size), offset_(0) {
    buf_ = static_cast<void*>(operator new(size));
}

template <typename T>
LinearAlloc<T>::~LinearAlloc() {
    operator delete(buf_);
}

template <typename T>
typename LinearAlloc<T>::pointer LinearAlloc<T>::allocate(size_t n) {
    if(offset_ + n * sizeof(T)> size_) {
        throw std::bad_alloc();
    }
    size_t aligned = this->align(offset_, alignof(T));
    offset_ = aligned + n * sizeof(T);
    char* c = reinterpret_cast<char*>(buf_);
    T* ptr = reinterpret_cast<T*>(c + aligned); 
    return ptr;
} 

template <typename T>
void LinearAlloc<T>::deallocate(T*, size_t) {}
  
template <typename T>
void LinearAlloc<T>::reset() {
    offset_ = 0;
}

template <typename T>
template <typename ...Args>
void LinearAlloc<T>::construct(T* ptr, Args&&... args) {
    new(ptr) T(std::forward<Args>(args)...); 
}

template <typename T>
void LinearAlloc<T>::destroy(LinearAlloc<T>::pointer ptr) {
    ptr->~T();
}

#endif