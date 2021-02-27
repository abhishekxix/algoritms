#include <bits/stdc++.h>

std::vector<int> add_binary(
    const std::vector<int> &a, const std::vector<int> &b) {
  assert(a.size() == b.size());
  int result_size = a.size() + 1;
  std::vector<int> result(result_size);
  int i = a.size() - 1;
  int k = result_size - 1;

  while (i >= 0) {
    if (
        (a.at(i) == 0 && b.at(i) == 0) ||
        (a.at(i) == 0 && b.at(i) == 1) ||
        (a.at(i) == 1 && b.at(i) == 0)) {
      result.at(k) = std::max(result.at(k), a.at(i) + b.at(i));
    } else {
      result.at(k) = std::max(0, result.at(k));
      if (k > 0) {
        result.at(k - 1) = 1;
      }
    }
    i--;
    k--;
  }

  return result;
}

int main() {
  std::vector<int> a = {1, 0};
  std::vector<int> b = {1, 1};
  auto result = add_binary(a, b);

  for (auto i : result) {
    std::cout << i;
  }
  std::cout << std::endl;

  return 0;
}
