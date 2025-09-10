#include <vector>
#include <iostream>
#include "Linear.hpp"

int main() {
    LinearAlloc<int> la(2000);
    int* ptr1 = la.allocate(2);
    la.construct(ptr1, 1);
    la.construct(ptr1 + 1, 2);
    std::cout << ptr1[0] << " " << ptr1[1] << std::endl;
    la.destroy(ptr1);
    int* ptr2 = la.allocate(4);
    la.construct(ptr2, 1);
    la.construct(ptr2 + 1, 2);
    la.construct(ptr2 + 2, 3);
    la.construct(ptr2 + 3, 4);
    std::cout << ptr2[0] << " " << ptr2[1] << " " << ptr2[2] << " " << ptr2[3] << std::endl;
    la.destroy(ptr1 + 1);
    la.destroy(ptr2);
    la.destroy(ptr2 + 1);
    la.destroy(ptr2 + 2);
    la.destroy(ptr2 + 3);
    la.reset();
    return 0;
}