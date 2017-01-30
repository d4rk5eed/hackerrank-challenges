#include <iostream>
#include <iomanip>
#include <limits>
#include <string>

using namespace std;

int main() {
  int i = 4;
  double d = 4.0;
  string s = "HackerRank ";

  string j_str;
  string e_str;
  string t_str;

  getline(cin, j_str);
  getline(cin, e_str);
  getline(cin, t_str);

  i += stoi(j_str);
  d += stod(e_str);
  s += t_str;

  cout << i << endl;
  cout << fixed <<  setprecision(1) << d << endl;
  cout << s << endl;

  return 0;
}
