#include <tuple>

std::tuple<uint64_t, uint64_t> Fib(size_t n)
{
  // 返回F_{n}和F_{n + 1}, 注意是对UINT64_MAX取模的结果.
  if (n > 0)
  {
    auto PF = Fib(n / 2);   // 基于递归求解.
    auto t0 = std::get<0>(PF);
    auto t1 = std::get<1>(PF);
    if (n % 2 == 1)         // 奇数情况.
      return {t0 * t0 + t1 * t1, (2 * t0 + t1) * t1};
    else
      return {(2 * t1 - t0) * t0, t0 * t0 + t1 * t1};
  }
  return {0, 1};            // 基础情形: F_0和F1.
}
