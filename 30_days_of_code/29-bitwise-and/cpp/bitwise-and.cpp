#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n, k, c;
  cin >> c;

  while(c--) {
    cin >> n >> k;
    cout << (((k-1) | k) <= n ? (k - 1) : (k - 2)) << endl;
  }
  return 0;
}
