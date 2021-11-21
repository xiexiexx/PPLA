#include <iostream>
#include <cmath>
#include <vector>

// 将Knuth的统计量计算程序改为C++代码.
// https://www-cs-faculty.stanford.edu/~knuth/programs/random-dfs-a.w

class statistics {
public:
  statistics()
    : n(0)
  {
    // 仅对计数值初始化.
  }
  // 记录数据x并迭代计算.
  void record(double x)
  {
    if (n++)
    {
      double tmp = x - mean;
      mean += tmp / n;
      var += tmp * (x - mean);
    }
    else
    {
      mean = x;
      var = 0;
    }
  }
  // 打印统计量.
  void print()
  {
    std::cout << mean << " +- "
              << (n > 1 ? sqrt(var / (n - 1)) : 0) << std::endl;
  }
private:
  double mean;
  double var;
  size_t n;
};


int main()
{
  std::vector<int> V {1, 2, 3, 4, 5};
  statistics S;
  for (const auto& x : V)
    S.record(x);
  S.print();
  return 0;
}
