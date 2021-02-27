#include <bits/stdc++.h>

void insertion_sort(std::vector<int> &a, int lb = 0, int ub = 0) {
  ub = ub == 0 ? a.size() : ub;
  lb = lb == 0 ? lb : lb - 1;

  for (int i = lb + 1; i < ub; i++) {
    int key = a.at(i);
    int j = i - 1;

    while (j >= lb && a.at(j) > key) {
      a.at(j + 1) = a.at(j);
      j--;
    }
    a.at(j + 1) = key;
  }
}

void insertion_sort_rev(std::vector<int> &a, int lb = 0, int ub = 0) {
  // ub = ub == 0 ? a.size() : ub;
  // lb = lb == 0 ? lb : lb - 1;

  // for (int i = ub - 2; i >= lb; i--) {
  //   int key = a.at(i);
  //   int j = i + 1;

  //   while (j <= ub - 1 && a.at(j) > key) {
  //     a.at(j - 1) = a.at(j);
  //     j++;
  //   }
  //   a.at(j - 1) = key;
  // }

  ub = ub == 0 ? a.size() : ub;
  lb = lb == 0 ? lb : lb - 1;

  for (int i = lb + 1; i < ub; i++) {
    int key = a.at(i);
    int j = i - 1;

    while (j >= lb && a.at(j) < key) {
      a.at(j + 1) = a.at(j);
      j--;
    }
    a.at(j + 1) = key;
  }
}

int main() {
  std::vector<int> a = {};
  /* for (int i = 20; i > 0; i--) {
    a.push_back(i);
  } */
  for (int i = 0; i < 1e6; i++) {
    a.push_back(i);
  }

  // insertion_sort(a, 3, 10);

  insertion_sort_rev(a);
  for (auto i : a) {
    std::cout << i << ' ';
  }

  std::cout << std::endl;

  return 0;
}
