#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

int find_low_bound(vector<int>& arr, int val, bool& found) {
  vector<int>::iterator p;
  p = lower_bound(arr.begin(), arr.end(), val);
  found = (*p == val);
  return (p - arr.begin()) + 1;
}
int main() {
  bool found;
  int n, index, val;
  vector<int> search_arr;
  cin >> n;

  search_arr.reserve(n);

  for(int i = 0; i < n; i++) {
    cin >> val;
    search_arr.push_back(val);
  }

  cin >> n;
  while(n--) {
    cin >> val;
    index = find_low_bound(search_arr, val, found);
    cout << (found ? "Yes" : "No") << " " << index << endl;
  }

  return 0;
}
