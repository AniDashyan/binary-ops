#ifndef BINARY_OPS_HPP
#define BINARY_OPS_HPP

#include <cstdint>

namespace BinaryOps 
{
    bool isPowerOfTwo(unsigned int x) 
    {
        return x && !(x & (x - 1));
    }

    enum class Endianness {
        LittleEndian,
        BigEndian,
        Unknown
    };

    Endianness detectEndianness() 
    {
        uint32_t num = 0x01020304;
        uint8_t* bytePtr = reinterpret_cast<uint8_t*>(&num);

        if (bytePtr[0] == 0x04)
            return Endianness::LittleEndian;
        else if (bytePtr[0] == 0x01)
            return Endianness::BigEndian;
        else
            return Endianness::Unknown;
    }

    void std_swap(int& a, int& b) 
    {
        int temp = a;
        a = b;
        b = temp;
    }

    void xor_swap(int& a, int& b) 
    {
        if (&a == &b) return; 
        a ^= b;
        b ^= a;
        a ^= b;
    }
}
#endif