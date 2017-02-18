#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  int c, erase_pos, erase_start, erase_stop;
  vector<int> arr;
  cin >> c;

  arr = vector<int>(c);
  for(auto& x: arr) {
    cin >> x;
  }

  cin >> erase_pos;
  arr.erase(arr.begin() + erase_pos-1);

  cin >> erase_start >> erase_stop;
  arr.erase(arr.begin() + erase_start-1, arr.begin() + erase_stop-1);

  cout << arr.size() << endl;

  for(auto const& x: arr) {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}
