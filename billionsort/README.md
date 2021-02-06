# parallel_billionsort

## MSVC

Visual Studio Community 2019.

- `/std:c++latest`
- `/O2`

## GCC

g++ 9 and libtbb-dev in Ubuntu 20.04.

- `g++ -O3 -std=c++17 parallel_billionsort.cpp -ltbb`