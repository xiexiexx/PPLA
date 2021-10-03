#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

template <typename T>
pair<size_t, size_t> solution_with_map(const vector<T>& V, T sum)
{
  map<T, pair<size_t, size_t>> M;
  for (size_t i = 0; i < V.size(); ++i)
  {
    auto iter = M.find(V[i]);
    if (iter == M.end())
      M.insert({V[i], {i, V.size()}});
    else
      iter->second.second = i;
  }
  for (auto ix = M.begin(); ix != M.end(); ++ix)
  {
    auto iy = M.find(sum - ix->first);
    if (iy == M.end())
      continue;
    if (ix != iy)
      return {ix->second.first, iy->second.first};
    else if (ix->second.second != V.size())
      return {ix->second.first, ix->second.second};
  }
  return {V.size(), V.size()};
}

template <typename T>
pair<size_t, size_t> solution_with_sort(const vector<T>& V, T sum)
{
  if (V.size() < 2)
    return {V.size(), V.size()};
  vector<pair<T, size_t>> M(V.size());
  for (size_t i = 0; i < V.size(); ++i)
    M[i] = {V[i], i};
  sort(M.begin(), M.end());
  size_t low = 0;
  size_t high = V.size() - 1;
  // 分支语句对右侧的判断数目略多, 也许可以随机选择左右并给出不同的次序.
  while (low + 1 <= high)
    if (M[low].first + M[high].first < sum)
      ++low;
    else if (sum < M[low].first + M[high].first)
      --high;
    else
      return {M[low].second, M[high].second};
  return {V.size(), V.size()};
}

int main()
{
  vector<int> V {3, 2, 3, 7, 5};
  pair<size_t, size_t> positions;
  positions = solution_with_map(V, 6);
  cout << positions.first << endl << positions.second << endl;
  positions = solution_with_sort(V, 9);
  cout << positions.first << endl << positions.second << endl;
  return 0;
}
