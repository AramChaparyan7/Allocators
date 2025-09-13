#include <vector>
#include <iostream>
#include "Debug.hpp"

int main() {
    std::vector<int, DebugAlloc<int>> v = {1, 2, 3};
    v.push_back(4);
    v.pop_back();
    return 0;
}