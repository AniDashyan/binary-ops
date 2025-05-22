#ifndef BINARY_OPS_HPP
#define BINARY_OPS_HPP

bool isPowerOfTwo(unsigned int x) {
    return x && !(x & (x - 1));
}

#endif