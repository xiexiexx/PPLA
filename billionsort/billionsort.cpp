#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

// 打印耗时情况.
inline void print_duration(std::chrono::steady_clock::time_point start_t,
                           std::chrono::steady_clock::time_point end_t)
{
  std::cout << (std::chrono::duration<double>(end_t - start_t).count() / 60)
            << " minutes" << std::endl;
}

int main()
{
  // 请注意: 10亿个数, 需要7.5GB内存.
  // 计时器start_t, end_t.

  // 内存分配.
  auto start_t = std::chrono::steady_clock::now();
  std::vector<double> V(1000000000);
  auto end_t = std::chrono::steady_clock::now();
  print_duration(start_t, end_t);

  // 数据赋值.
  start_t = std::chrono::steady_clock::now();
  // 利用随机数生成器生成0.0到1.0之间的实数.
  std::default_random_engine generator(time(NULL));
  std::uniform_real_distribution<double> distribution(0.0, 1.0);
  for (auto& x : V)
    x = distribution(generator);
  end_t = std::chrono::steady_clock::now();
  print_duration(start_t, end_t);

  // 串行排序.
  start_t = std::chrono::steady_clock::now();
  // 对10亿个随机数排序, 如果用数组时间也没什么太大差别.
  std::sort(V.begin(), V.end());
  end_t = std::chrono::steady_clock::now();
  print_duration(start_t, end_t);

  return 0;
}
