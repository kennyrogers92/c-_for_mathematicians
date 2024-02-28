#include "quaternion.h"
#include <iostream>

int main() {
    quaternion A (1,2,3,-4);
    quaternion B (1, -2, -3, 4);
    std::cout << (1./A)*A << std::endl; 
}