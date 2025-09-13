#ifndef LINEARCPP
#define LINEARCPP
#include "Debug.hpp"

template <typename T>
typename DebugAlloc<T>::pointer DebugAlloc<T>::allocate(size_t n) {
    T* p = static_cast<T*>(::operator new(n * sizeof(T)));
    std::cout << "Allocated at address" << p << " : " << n << " elements" << std::endl;
    return p;
} 

template <typename T>
void DebugAlloc<T>::deallocate(T* ptr, size_t n) {
    ::operator delete(ptr);
    std::cout << "Deallocated at address" << ptr<< std::endl;
}
  

template <typename T>
template <typename ...Args>
void DebugAlloc<T>::construct(T* ptr, Args&&... args) {
    new(ptr) T(std::forward<Args>(args)...); 
    std::cout << "Constructed at addres" << ptr << " with arguments ";
    ((std::cout << args << " "), ...);
    std::cout << std::endl;
}

template <typename T>
void DebugAlloc<T>::destroy(DebugAlloc<T>::pointer ptr) {
    ptr->~T();
    std::cout << "Destructed at addres " << ptr << std::endl;
}

#endif