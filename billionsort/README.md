# billionsort

MSVC/GCC/Clang.

- billionsort
- billionsort_heap
- billionsort_forward_list
- billionsort_set

# parallel_billionsort

## MSVC

Visual Studio Community 2019.

- `/std:c++latest` `/O2`

## GCC

g++ 9 and libtbb-dev in Ubuntu 20.04.

- `g++ -O3 -std=c++17 parallel_billionsort.cpp -ltbb`

## Clang

It does not yet support `execution`.

# Binary Files

- [MSVC](/bin/)
