#include <bits/stdc++.h>

int linear_search(std::vector<int> &a, int search_item) {
  for (int i = 0; i < a.size(); i++) {
    if (a.at(i) == search_item) {
      return i;
    }
  }
  return -1;
}

int main() {
  std::vector<int> a = {};
  for (int i = 20; i >= 0; i--) {
    a.push_back(i);
  }

  std::cout << linear_search(a, 3);

  std::cout << std::endl;
  return 0;
}