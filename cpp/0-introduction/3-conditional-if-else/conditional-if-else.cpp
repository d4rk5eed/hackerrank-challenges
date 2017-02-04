#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int input;

  string integers[] =
    {"", "one", "two", "three", "four", "five", "six",
     "seven", "eight", "nine"};

  cin >> input;

  if(input >= 1 && input <= 9)
    cout << integers[input] << endl;
  else if(input > 9)
    cout << "Greater than 9" << endl;

  return 0;
}
