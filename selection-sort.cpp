#include <bits/stdc++.h>

void selection_sort(std::vector<int> &a) {
  for (int i = 0; i < a.size() - 1; i++) {
    int min = i;
    for (int j = i + 1; j < a.size(); j++) {
      if (a.at(j) < a.at(min)) {
        min = j;
      }
    }
    int temp = a.at(i);
    a.at(i) = a.at(min);
    a.at(min) = temp;
  }
}

int main() {
  std::vector<int> a = {};
  for (int i = 20; i > 0; i--) {
    a.push_back(i);
  }

  selection_sort(a);

  for (auto i : a) {
    std::cout << i << ' ';
  }

  std::cout << std::endl;

  return 0;
}