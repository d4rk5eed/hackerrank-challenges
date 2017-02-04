#include <iostream>
#include <iomanip>      // std::setprecision
using namespace std;

int main() {
  int a;
  long b;
  long long c;
  char d;
  float e;
  double f;
  cin >> a >> b >> c >> d >> e >> f;
  cout << a << endl << b << endl << c << endl << d << endl << setprecision(8) << e << endl << setprecision(16) << f << endl;
  // Complete the code.
  return 0;
}
