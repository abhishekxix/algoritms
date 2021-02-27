#include <bits/stdc++.h>

void merge(std::vector<int> &a, int p, int q, int r) {
  std::vector<int> left(q - p + 1);
  std::vector<int> right(r - q);

  for (int i = 0; i < left.size(); i++) {
    left.at(i) = a.at(p + i);
  }

  for (int j = 0; j < right.size(); j++) {
    right.at(j) = a.at(q + j + 1);
  }

  int i = 0;
  int j = 0;
  int k = p;

  while (i < left.size() and j < right.size()) {
    if (left.at(i) <= right.at(j)) {
      a.at(k) = left.at(i);
      i++;
    } else {
      a.at(k) = right.at(j);
      j++;
    }
    k++;
  }

  while (i < left.size()) {
    a.at(k) = left.at(i);
    i++;
    k++;
  }

  while (j < right.size()) {
    a.at(k) = right.at(j);
    j++;
    k++;
  }
}

void merge_sort(std ::vector<int> &a, int p, int r) {
  if (p < r) {
    int q = p + ((r - p) / 2);
    merge_sort(a, p, q);
    merge_sort(a, q + 1, r);
    merge(a, p, q, r);
  }
}
int main() {
  std::vector<int> a{5, 4, 3, 2, 1};
  for (int i = 0; i < 1e6; i++) {
    a.push_back(i);
  }

  merge_sort(a, 0, a.size() - 1);
  for (auto i : a) {
    std::cout << i << " ";
  }

  std::cout << std::endl;
  return 0;
}
