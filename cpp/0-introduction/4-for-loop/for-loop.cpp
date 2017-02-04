#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main() {
  int start, end;

  vector<string> numbers =
    {"", "one", "two", "three", "four", "five", "six",
     "seven", "eight", "nine"};

  cin >> start >> end;

  for (int n = start; n <= end; n++ ) {
    if(n < numbers.size())
      cout << numbers[n] << endl;
    else if((n & 1) == 1)
      cout << "odd" << endl;
    else if((n & 1) == 0)
      cout << "even" << endl;
  }

  return 0;
}
