#include <bits/stdc++.h>

class Range : std::pair<int, int> {
 private:
  int first;
  int second;

 public:
  int low() {
    return this->first;
  }

  int high() {
    return this->second;
  }

  void low(int value) {
    first = value;
  }

  void high(int value) {
    second = value;
  }

  Range(int low, int high) {
    first = low;
    second = high;
  }

  void range(int low, int high) {
    first = low;
    second = high;
  }
};

std::pair<Range, int> maximun_crossing_subarray(
    const std::vector<int>& a, int low, int mid, int high) {
  int left_sum = INT_MIN;
  int max_left = mid;
  int sum = 0;
  for (int i = mid; i >= low; i--) {
    sum += a.at(i);
    if (sum > left_sum) {
      max_left = i;
      left_sum = sum;
    }
  }

  sum = 0;
  int right_sum = INT_MIN;
  int max_right = mid;
  for (int i = mid + 1; i <= high; i++) {
    sum += a.at(i);
    if (sum > right_sum) {
      max_right = i;
      right_sum = sum;
    }
  }

  return std::make_pair(Range(max_left, max_right), left_sum + right_sum);
}

std::pair<Range, int> maximum_subarray(
    const std::vector<int>& a, int low, int high) {
  if (low == high) return std::make_pair(Range(low, high), a.at(low));

  int mid = low + (high - low) / 2;

  std::pair<Range, int> left_half = maximum_subarray(a, low, mid);
  std::pair<Range, int> right_half = maximum_subarray(a, mid + 1, high);
  std::pair<Range, int> crossing = maximun_crossing_subarray(a, low, mid, high);

  std::pair<Range, int> largest(Range(0, 0), INT_MIN);
  int left_sum = left_half.second;
  int right_sum = right_half.second;
  int crossing_sum = crossing.second;

  Range largest_range(0, 0);
  int largest_sum = INT_MIN;

  if (left_sum > right_sum) {
    if (left_sum > crossing_sum) {
      largest_range.range(left_half.first.low(), left_half.first.high());
      largest_sum = left_sum;
    } else {
      largest_range.range(crossing.first.low(), crossing.first.high());
      largest_sum = crossing_sum;
    }
  } else {
    if (right_sum > crossing_sum) {
      largest_range.range(right_half.first.low(), right_half.first.high());
      largest_sum = right_sum;
    } else {
      largest_range.range(crossing.first.low(), crossing.first.high());
      largest_sum = crossing_sum;
    }
  }

  largest.first.range(largest_range.low(), largest_range.high());
  largest.second = largest_sum;

  return largest;
}

int main() {
  std::vector<int> a{13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
  std::pair<Range, int> largest_subarray = maximum_subarray(a, 0, a.size() - 1);

  std::cout << "(" << largest_subarray.first.low() << ", "
            << largest_subarray.first.high() << ")"
            << " : " << largest_subarray.second << "\n";
  return 0;
}
