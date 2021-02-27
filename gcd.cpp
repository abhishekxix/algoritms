#include <bits/stdc++.h>

int gcd(int a, int b) {
  if (a == 0) {
    return b;
  }
  if (b == 0) {
    return a;
  }

  return gcd(b, a % b);
}

int main() {
  std::cout << gcd(200, 4) << '\n';

  return 0;
}