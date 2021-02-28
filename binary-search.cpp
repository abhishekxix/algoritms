#include <bits/stdc++.h>

int binary_search(const std::vector<int> &a, int low, int high, int key) {
  // if (low <= high) {
  //   int mid = low + (high - low) / 2;
  //   if (a.at(mid) == key) return mid;

  //   if (a.at(mid) > key) return binary_search(a, low, mid - 1, key);

  //   return binary_search(a, mid + 1, high, key);
  // }

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (a.at(mid) == key) return mid;

    if (a.at(mid) > key)
      high = mid - 1;

    else
      low = mid + 1;
  }

  return -1;
}

int main() {
  std::vector<int> a = {1, 2, 3, 4, 5, 6};

  std::cout << binary_search(a, 0, a.size() - 1, 4);
  return 0;
}