#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int c;
  vector<int> arr;
  cin >> c;

  arr = vector<int>(c);
  for(auto& x: arr) {
    cin >> x;
  }

  sort(arr.begin(), arr.end());

  for(auto const& x: arr) {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}
