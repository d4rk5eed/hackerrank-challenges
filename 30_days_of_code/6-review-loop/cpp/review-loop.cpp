#include <iostream>
#include <string>
using namespace std;

int main() {
  int n;
  string str;

  cin >> n;

  while(n--) {
    cin >> str;

    for(size_t x = 0; x < str.size(); x +=2) {
      cout << str[x];
    }
    cout << " ";

    for(size_t x = 1; x < str.size(); x +=2) {
      cout << str[x];
    }
    cout << endl;
  }

  return 0;
}
