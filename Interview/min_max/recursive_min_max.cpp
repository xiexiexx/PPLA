#include <iostream>
#include <string>
#include <random>
#include <algorithm>

#include <utility>
#include <vector>

using namespace std;

// 假定非空向量V的长度为2的幂.
size_t n = 16777216;
vector<int> V(n);

// 为了测试性能, 仅处理上述约定情况下的V, 递归求出最小值和最大值.
pair<int, int> recursive_min_max(size_t left, size_t right)
{
  if (right - left > 2)
  {
    size_t middle = 1 + left + (right - left) / 2;
    pair<int, int> result_left = recursive_min_max(left, middle);
    pair<int, int> result_right = recursive_min_max(middle, right);
    return {result_left.first < result_right.first ? result_left.first : result_right.first,
            result_left.second < result_right.second ? result_right.second : result_left.second};
  }
  else if (V[left] < V[right - 1])
    return {V[left], V[right - 1]};
  else
    return {V[right - 1], V[left]};
}

int main()
{
  for (size_t i = 0; i < n; ++i)
    V[i] = i;
  auto result = recursive_min_max(0, V.size());
  cout << result.first << endl << result.second << endl;
  return 0;
}
