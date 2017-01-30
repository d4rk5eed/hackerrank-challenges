#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
  double meal_cost;
  int tip_percent, tax_percent;

  double tip, tax;

  cin >> meal_cost;
  cin >> tip_percent;
  cin >> tax_percent;

  tip = meal_cost * tip_percent / 100;
  tax = meal_cost * tax_percent / 100;

  cout << "The total meal cost is " << (int)round(meal_cost + tip + tax) << " dollars." << endl;

  return 0;
}
