#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <execution>

// 需要支持C++17的execution, 运行环境为MSVC 2017以上.

// 打印耗时情况.
inline void print_duration(std::chrono::steady_clock::time_point start_t,
    std::chrono::steady_clock::time_point end_t)
{
    std::cout << std::chrono::duration<double>(end_t - start_t).count()
        << " seconds" << std::endl;
}

int main()
{
  // 计时器start_t, end_t.

  // 内存分配计时开始.
  auto start_t = std::chrono::steady_clock::now();
  // 10亿个数, 需要7.5GB内存.
  // 换用malloc申请动态数组, 此处速度会更快.
  // 并行排序可能还需要额外较多内存, 最好留存16GB内存.
  std::vector<double> V(1000000000);
  // 内存分配计时结束并输出时间.
  auto end_t = std::chrono::steady_clock::now();
  std::cout << "Preparation: ";
  print_duration(start_t, end_t);

  // 数据赋值计时开始.
  start_t = std::chrono::steady_clock::now();
  // 利用随机数生成器生成0.0到1.0之间的实数.
  std::default_random_engine generator(time(NULL));
  std::uniform_real_distribution<double> distribution(0.0, 1.0);
  // 仍为串行赋值, 并行随机数生成较为复杂, 特别是要保持与串行所生成数据一致.
  for (auto& x : V)
    x = distribution(generator);
  // 数据赋值计时结束并输出时间.
  end_t = std::chrono::steady_clock::now();
  std::cout << "Initialization: ";
  print_duration(start_t, end_t);

  // 排序计时开始.
  start_t = std::chrono::steady_clock::now();
  // 对10亿个随机数以并行算法排序, 如果用数组时间也没什么太大差别.
  std::sort(std::execution::par, V.begin(), V.end());
  // 排序计时结束并输出时间.
  end_t = std::chrono::steady_clock::now();
  std::cout << "Sorting: ";
  print_duration(start_t, end_t);

  return 0;
}
