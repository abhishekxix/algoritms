#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mod (ll)((1e9) + 7)
#define comp_float (1e-9)
#define PI M_PI
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)

// Classes
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

//Functions
std::string &reverse(std::string &str) {
  ll length = str.length();
  char temp{};
  if (length == 0) return str;
  for (ll i = 0; i < length / 2; i++) {
    temp = str[i];
    str[i] = str[length - i - 1];
    str[length - i - 1] = temp;
  }

  return str;
}

char *reverse(char *str) {
  if (str == nullptr) return str;

  ll length = strlen(str);
  char temp{};

  for (ll i = 0; i < length / 2; i++) {
    temp = str[i];
    str[i] = str[length - i - 1];
    str[length - i - 1] = temp;
  }

  return str;
}

ll gcd(ll a, ll b, ll c) {
  return std::__gcd(a, std::__gcd(b, c));
}

ll gcd(ll a, ll b, ll c, ll d) {
  return std::__gcd(std::__gcd(a, b), std::__gcd(c, d));
}

ll lcm(ll a, ll b) {
  return (a * b) / std::__gcd(a, b);
}

ll lcm(ll a, ll b, ll c) {
  return lcm(a, lcm(b, c));
}

ll lcm(ll a, ll b, ll c, ll d) {
  return lcm(lcm(a, b), lcm(c, d));
}

ll gcpf(ll a, ll b) {
  ll gcd = std::__gcd(a, b);
  if (gcd == 1)
    return gcd;
  ll largest{1};

  if (gcd % 2 == 0) {
    largest = std::max(largest, 2LL);
  }

  while (gcd % 2 == 0) {
    gcd /= 2;
  }

  for (ll i = 3; i <= sqrt(gcd); i += 2) {
    if (gcd % i == 0)
      largest = std::max(largest, (ll)i);

    while (gcd % i == 0) {
      gcd /= i;
    }
  }

  if (gcd > 2) {
    largest = std::max(largest, gcd);
  }

  return largest;
}

ll gcpf(ll a, ll b, ll c) {
  return gcpf(a, gcpf(a, b));
}

ll gcpf(ll a, ll b, ll c, ll d) {
  return gcpf(gcpf(a, b), gcpf(c, d));
}

ll binary_search(std::vector<ll> &a, ll l, ll r, ll key) {
  ll mid{};

  while (l <= r) {
    mid = l + (r - l) / 2;

    if (a.at(mid) == key) {
      return mid;
    } else if (key < a.at(mid)) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  return l;
}

ll binary_search_nf(std::vector<ll> &a, ll l, ll r, ll key) {
  ll mid{};

  while (l <= r) {
    mid = l + (r - l) / 2;

    if (a.at(mid) == key) {
      return mid;
    } else if (key < a.at(mid)) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  return -1;
}

ll binary_search_nf(std::string &s, char key) {
  ll l = 0;
  ll mid{};
  ll r = s.size() - 1;

  while (l <= r) {
    mid = l + (r - l) / 2;

    if (s.at(mid) == key) {
      return mid;
    } else if (key < s.at(mid)) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  return -1;
}

ll binary_search_reverse(std::vector<ll> &a, ll l, ll r, ll key) {
  ll mid{};

  while (l <= r) {
    mid = l + (r - l) / 2;

    if (a.at(mid) == key) {
      return mid;
    }
    if (a.at(mid) > key) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return r;
}

template <typename T>
void input_vector(std::vector<T> &a) {
  for (auto &i : a) {
    std::cin >> i;
  }
}

bool is_prime(ull n) {
  for (int i{}; i <= (ull)sqrt(n); i++) {
    if (!(n % i)) {
      return false;
    }
  }

  return true;
}

ll modulo(ll a, ll b) {
  if (a >= 0) {
    return a % b;
  }
  return a + b;
}

/**
 * std::sort(v.begin(), v.end(), greater<T>()) sorts the elements in escending order.
*/

std::pair<Range, ll> max_subarray_sum(const std::vector<ll> &a) {
  ll high = 0;
  ll low = 0;
  ll max_sum = INT_MIN;
  ll current_sum = 0;
  ll current_low = 0;
  ll current_high = 0;

  for (int i = 0; i < a.size(); i++) {
    current_high = i;

    if (current_sum > 0) {
      current_sum += a.at(i);
    } else {
      current_low = i;
      current_sum = a.at(i);
    }

    if (current_sum > max_sum) {
      high = current_high;
      low = current_low;
      max_sum = current_sum;
    }
  }
  return std::make_pair(Range(low, high), max_sum);
}

//start solving the problem in this function.
void solve() {
  ll n;
  std::cin >> n;
  std::vector<ll> a(n);
  input_vector(a);
  auto result = max_subarray_sum(a);
  std::cout << "(" << result.first.low() << ", "
            << result.first.high() << ") : " << result.second;
}

int main() {
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::ios::sync_with_stdio(false);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  solve();

  return 0;
}