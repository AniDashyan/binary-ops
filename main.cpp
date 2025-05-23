#include <iostream>
#include <cassert>
#include "kaizen.h"
#include "binary_ops.hpp"

using namespace BinaryOps;

void test_isPowerOfTwo() {
    assert(isPowerOfTwo(1) == true);
    assert(isPowerOfTwo(2) == true);
    assert(isPowerOfTwo(4) == true);
    assert(isPowerOfTwo(1024) == true);
    assert(isPowerOfTwo(0) == false);
    assert(isPowerOfTwo(3) == false);
    assert(isPowerOfTwo(100) == false);
    zen::log("isPowerOfTwo tests passed.");
}

void test_detectEndianness() {
    Endianness e = detectEndianness();
    zen::print("System Endianness: ");
    switch (e) {
        case Endianness::LittleEndian: zen::print("LittleEndian\n"); break;
        case Endianness::BigEndian: zen::print("BigEndian\n"); break;
        default: zen::print("Unknown\n"); break;
    }
}

void test_swap(const std::string& name, void(*swapFunc)(int&, int&)) {
    const int iterations = 1000000;
    std::mt19937 rng(42);
    std::uniform_int_distribution<int> dist(1, 1000000);
    zen::timer t;

    int dummy = 0;

    t.start();
    for (int i = 0; i < iterations; ++i) {
        int a = dist(rng);
        int b = dist(rng);
        swapFunc(a, b);
        dummy += a + b;
    }
    t.stop();
    auto duration = t.duration<zen::timer::msec>().count();

    zen::log(name, " duration for ", iterations, " random swaps: ", duration, "ms");
}

int main() {
    test_isPowerOfTwo();
    test_detectEndianness();
    test_swap("std_swap", std_swap);
    test_swap("xor_swap", xor_swap);
    test_swap("std_swap", std_swap);
    test_swap("xor_swap", xor_swap);
    zen::print("All tests completed.");
    return 0;
}