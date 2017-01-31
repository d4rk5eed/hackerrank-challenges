#include <iostream>
#include <algorithm>
using namespace std;

int max_of_four(int a, int b, int c, int d) {
  int list[] = {a, b, c, d};

  return *max_element(list, list + 4);
}

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int ans = max_of_four(a, b, c, d);
  cout << ans << endl;

  return 0;
}
