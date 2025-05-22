#include <iostream>
#include <cassert>
#include "binary_ops.hpp"


int main() {
    assert(isPowerOfTwo(1) == true);   
    assert(isPowerOfTwo(2) == true);  
    assert(isPowerOfTwo(5) == false);  
    assert(isPowerOfTwo(8) == true);   
    assert(isPowerOfTwo(64) == true); 
    assert(isPowerOfTwo(127) == true); 
    assert(isPowerOfTwo(256) == true); 
    return (0);
}