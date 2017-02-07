#include <iostream>
using namespace std;


int main() {
  int n;
  cin >> n;
  int count =0, max =0;
  for(int x = 1; x < n; x *= 2) {
    if((n & x) == x) {count++;}
    else { (count > max) && (max = count); count =0;}
  }
  (count > max) && (max = count);
  cout << max << endl;
  return 0;
}
