#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

  int a, b, c;
  bool error ;

  do {
    error = false;

    cin >> a >> b >> c;

    if(!(a <= 1000 && a >= 1 && b <= 1000 && b >= 1 && c <= 1000 && c >= 1)){
      error = true;
      cout << "Constraints denied" << endl ;
    }
  } while(error);

  cout << a + b + c << endl ;
  return 0;
}
