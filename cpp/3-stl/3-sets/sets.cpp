#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
  set<int> container;
  set<int>::iterator p;
  int n, q, val;

  cin >> n;
  while(n--) {
    cin >> q >> val;
    switch(q) {
    case 1:
      container.insert(val);
      break;
    case 2:
      container.erase(val);
      break;
    case 3:
      p = container.find(val);
      cout << (p!=container.end() ? "Yes" : "No") << endl;
    }
  }
  return 0;
}
