#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

template <typename T>
pair<size_t, size_t> solution_with_map(const vector<T>& V, T m)
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
  for (auto tx = M.begin(); tx != M.end(); ++tx)
  {
    auto ty = M.find(m - tx->first);
    if (ty == M.end())
      continue;
    if (tx != ty)
      return {tx->second.first, ty->second.first};
    else if (tx->second.second != V.size())
      return {tx->second.first, tx->second.second};
  }
  return {V.size(), V.size()};
}

template <typename T>
pair<size_t, size_t> solution_with_map_check(const vector<T>& V, T m)
{
  map<T, size_t> M;
  for (size_t i = 0; i < V.size(); ++i)
  {
    auto ty = M.find(V[i]);
    if (ty == M.end())
    {
      T difference = m - V[i];
      auto tx = M.find(difference);
      if (tx != M.end())
        return {tx->second, i};
      M.insert({V[i], i});
    }
    else if (V[i] + V[i] == m)
      return {ty->second, i};
  }
  return {V.size(), V.size()};
}

template <typename T>
pair<size_t, size_t> solution_with_sort(const vector<T>& V, T m)
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
    if (M[low].first + M[high].first < m)
      ++low;
    else if (m < M[low].first + M[high].first)
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
  positions = solution_with_map_check(V, 6);
  cout << positions.first << endl << positions.second << endl;
  positions = solution_with_sort(V, 9);
  cout << positions.first << endl << positions.second << endl;
  return 0;
}
