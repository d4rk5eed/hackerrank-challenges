#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void update(int *a,int *b) {
  int a_tmp = *a, b_tmp = *b;
  (*a) = a_tmp + b_tmp;
  (*b) = abs(a_tmp - b_tmp);
}

int main() {
  int a, b;
  int *pa = &a, *pb = &b;

  cin >> a >>  b;
  update(pa, pb);
  cout << a << endl <<  b << endl;

  return 0;
}
