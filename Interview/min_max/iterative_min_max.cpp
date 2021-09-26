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

// 为了测试性能, 仅处理上述约定情况下的V, 迭代求出最小值和最大值.
pair<int, int> iterative_min_max()
{
  pair<int, int> result;
  if (V[0] < V[1])
    result = {V[0], V[1]};
  else
    result = {V[1], V[0]};
  for (size_t i = 2; i < V.size(); ++i)
    if (V[i] < result.first)
      result.first = V[i];
    else if (result.second < V[i])
      result.second = V[i];
  return result;
}

int main()
{
  for (size_t i = 0; i < n; ++i)
    V[i] = i;
  auto result = iterative_min_max();
  cout << result.first << endl << result.second << endl;
  return 0;
}
