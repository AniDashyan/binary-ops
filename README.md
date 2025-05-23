# Binary Operations

## Overview

This C++ project explores and benchmarks several low-level binary operations:

- **Power-of-Two Detection**: Determine if a number is a power of two using bitwise logic.
- **Endianness Detection**: Identify whether the current system is little-endian or big-endian at runtime.
- **Swap Algorithms**: Compare the performance of a traditional `std_swap` using a temporary variable and an `xor_swap` that uses XOR bitwise operations.

It also features benchmarking logic using a custom `zen` utility (assumed to be provided by `kaizen.h`) to test and compare execution times.

## Build & Run

### Prerequisites
- A C++17-compatible compiler (e.g., GCC 9+, Clang 10+, MSVC 2019+)
- CMake 3.10+
- Git

### Steps

```bash
# Clone the repository
git clone https://github.com/AniDashyan/binary-ops
cd binary-ops
```

```bash
# Configure and build
cmake -S . -B build
cmake --build build
```

```bash 
# Run the executable
./build/bit_ops
```

## Example Output

```text
isPowerOfTwo tests passed. 
System Endianness: LittleEndian
std_swap  duration for  1000000  random swaps:  45 ms
xor_swap  duration for  1000000  random swaps:  26 ms
std_swap  duration for  1000000  random swaps:  45 ms
xor_swap  duration for  1000000  random swaps:  26 ms
All tests completed.
```
Execution time may vary based on CPU and system load.

## Code Structure

* **binary\_ops.hpp**: Contains the implementation of:

  * `isPowerOfTwo()`
  * `detectEndianness()`
  * `std_swap()` and `xor_swap()`

* **main.cpp**: Contains test cases and performance benchmarking code using random inputs and fixed iterations.
