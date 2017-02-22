#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool is_prime(int value) {
  if(value == 1)
    return false;
  if(value == 2 || value == 3)
    return true;

  for(int i = 2; i * i <= value; i++) {
    if(value % i == 0)
      return false;
  }

  return true;
}

int main() {
  int n;

  cin >> n;
  vector<int> int_vector(n);
  for (auto& i: int_vector) {
    cin >> i;
  }

  for (const auto& i: int_vector) {
    cout << (is_prime(i) ? "Prime" : "Not prime") << endl;
  }
  return 0;
}
