#include <vector>
#include <iostream>
#include <string>
#include <iomanip>

void print_line(const std::vector<uint64_t>& V,
                uint64_t i, uint64_t n, int width)
{
  // 以(n - i) * width为宽度打印前导空格.
  std::cout << std::string((n - i) * width, ' ');
  // 每项及其后的空格均占width宽度.
  for (const auto& x : V)
    std::cout << std::setw(width) << x << std::string(width, ' ');
  std::cout << std::endl;
}

int main()
{
  std::vector<uint64_t> V;
  uint64_t n = 12;
  int width = 3;
  V.reserve(n + 1);

  // 正向生成二项式系数.
  for (uint64_t i = 0; i <= n; ++i)
  {
    uint64_t prev = 1;
    for (uint64_t j = 1; j < V.size(); ++j)
    {
      uint64_t temp = V[j];
      V[j] += prev;
      prev = temp;
    }
    V.push_back(1);
    print_line(V, i, n, width);
  }

  // 逆向生成二项式系数.
  V.resize(0);
  for (uint64_t i = 0; i <= n; ++i)
  {
    V.push_back(1);
    uint64_t j = i;
    while (j-- > 1)
      V[j] += V[j - 1];
    print_line(V, i, n, width);
  }

  return 0;
}
