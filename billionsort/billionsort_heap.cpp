#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

int main()
{
  // 计时器start_t, end_t.

  // 内存分配计时开始.
  auto start_t = std::chrono::steady_clock::now();
  std::vector<double> V(1000000000);  // 10亿个数, 需要7.5GB内存.
  // 内存分配计时结束并输出时间.
  auto end_t = std::chrono::steady_clock::now();
  std::cout << (std::chrono::duration<double>(end_t - start_t).count() / 60)
            << " minutes" << std::endl;

  // 数据赋值计时开始.
  start_t = std::chrono::steady_clock::now();
  // 利用随机数生成器生成0.0到1.0之间的实数.
  std::default_random_engine generator(time(NULL));
  std::uniform_real_distribution<double> distribution(0.0, 1.0);
  for (size_t i = 0; i < V.size(); ++i)
    V[i] = distribution(generator);
  // 数据赋值计时结束并输出时间.
  end_t = std::chrono::steady_clock::now();
  std::cout << (std::chrono::duration<double>(end_t - start_t).count() / 60)
            << " minutes" << std::endl;

  // 排序计时开始.
  start_t = std::chrono::steady_clock::now();
  // 基于堆排序对10亿个随机数排序.
  std::make_heap(V.begin(), V.end());
  std::sort_heap(V.begin(), V.end());
  // 排序计时结束并输出时间.
  end_t = std::chrono::steady_clock::now();
  std::cout << (std::chrono::duration<double>(end_t - start_t).count() / 60)
            << " minutes" << std::endl;

  return 0;
}
