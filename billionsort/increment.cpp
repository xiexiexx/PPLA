#include <iostream>
#include <chrono>

// 不要设置任何编译器优化.
// 注意代码中全部使用int会更快, 因为int仅需4个字节.

// 获取耗时情况. 计时器start_t, end_t.
inline double get_duration(std::chrono::steady_clock::time_point start_t,
                         std::chrono::steady_clock::time_point end_t)
{
  return std::chrono::duration<double>(end_t - start_t).count();
}

int main()
{
  const size_t m = 42;
  const size_t n = 10000000;
  double l = 0;
  double r = 0;

  for (size_t k = 0; k < m; ++k)
  {
    // 空循环.
    auto start_t = std::chrono::steady_clock::now();
    for (size_t i = 0; i < n; ++i)
      ;
    auto end_t = std::chrono::steady_clock::now();
    l += get_duration(start_t, end_t);

    // 仅做x自增的循环.
    size_t x = 0;
    start_t = std::chrono::steady_clock::now();
    for (size_t i = 0; i < n; ++i)
      ++x;
    end_t = std::chrono::steady_clock::now();
    r += get_duration(start_t, end_t);
  }
  l /= m;
  r /= m;

  std::cout << l << std::endl;
  std::cout << r << std::endl;
  // 单次自增操作大约耗时.
  std::cout << (r - l) / n << std::endl;
  // 形成循环的最小结构与单次自增耗时之比.
  std::cout << l / (r - l) << std::endl;
  return 0;
}
