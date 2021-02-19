#include <iostream>
#include <string>
#include <algorithm>
#include <functional>

int main()
{
  std::string p = "Algorithm_";
  std::string t = "Data Structures and Algorithms";
  auto iter = std::search(t.begin(), t.end(), p.begin(), p.end());
  std::cout << iter - t.begin() << std::endl;
  p = "Algorithms";
  iter = std::search(t.begin(), t.end(),
                     std::boyer_moore_searcher(p.begin(), p.end()));
  std::cout << iter - t.begin() << std::endl;
  p = "Data";
  iter = std::search(t.begin(), t.end(),
                     std::boyer_moore_horspool_searcher(p.begin(), p.end()));
  std::cout << iter - t.begin() << std::endl;
  return 0;
}
