#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

int count_fine(int e_day, int e_month, int e_year,
               int a_day, int a_month, int a_year) {
  if(a_year>e_year)
    return 10000;
  else if(a_month > e_month && e_year == a_year)
    return (a_month - e_month) * 500;
  else if(a_day > e_day && e_year == a_year && e_month == a_month)
    return (a_day - e_day) * 15;

  return 0;
}

int main() {
  assert(count_fine(1, 1, 2010, 31, 12, 2009) == 0);
  assert(count_fine(19, 9, 2468, 23, 12, 1234) == 0);
  assert(count_fine(10, 10, 2010, 9, 10, 2011) == 10000);
  assert(count_fine(10, 10, 2010, 9, 11, 2010) == 500);
  assert(count_fine(10, 10, 2010, 11, 10, 2010) == 15);
  assert(count_fine(10, 10, 2010, 9, 10, 2010) == 0);

  int e_day, e_month, e_year,
    a_day, a_month, a_year;

  cin >> a_day >> a_month >> a_year;
  cin >> e_day >> e_month >> e_year;

  cout << count_fine(e_day, e_month, e_year, a_day, a_month, a_year) << endl;
  return 0;
}
