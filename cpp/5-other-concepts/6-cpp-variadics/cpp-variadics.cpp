#include <iostream>
#include <array>
#include <bitset>
using namespace std;

template <int n, bool...digits>
struct CheckValues {
  static void check(int x, int y)
  {
    CheckValues<n-1, 0, digits...>::check(x, y);
    CheckValues<n-1, 1, digits...>::check(x, y);
  }
};

template <bool... args> int reversed_binary_value() {
  std::array<bool, sizeof...(args)> ar{args...};
  std::bitset<sizeof...(args)> bs;
  for(std::size_t i = 0; i < ar.size(); ++i) {
    bs[i] = ar[i];
  }
  return bs.to_ulong();
}


template <bool...digits>
struct CheckValues<0, digits...> {
  static void check(int x, int y)
  {
    int z = reversed_binary_value<digits...>();
    std::cout << (z+64*y==x);
  }
};

int main()
{
  // assert(reversed_binary_value<bool>(true) == "1");
  // assert(reversed_binary_value<bool>(false) == "0");

  // assert(reversed_binary_value<bool>(true, false) == "01");
  // assert(reversed_binary_value<bool>(false, true) == "10");

  int t; std::cin >> t;

  for (int i=0; i!=t; ++i) {
    int x, y;
    cin >> x >> y;
    CheckValues<6>::check(x, y);
    cout << "\n";
  }
}
