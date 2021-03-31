#include <iostream>

using std::cin;
using std::cout;
using std::endl;

uint64_t Fibonacci(size_t n)
{
  if (n < 2)
    return n;
  uint64_t x = 0;
  uint64_t y = 1;
  // 也可以只用n控制循环, while (n-- > 2)即可.
  for (size_t i = 2; i < n; ++i)
  {
    uint64_t f = x + y;
    x = y;
    y = f;
  }
  return x + y;
}

int main()
{
  size_t n;
  cin >> n;
  cout << Fibonacci(n) << endl;
  return 0;
}
