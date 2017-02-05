#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<int> parseInts(string str) {
  stringstream stream;
  vector<int> result;
  int x;
  char comma;

  stream.str(str);
  while(stream >> x) {
    result.push_back(x);
    stream >> comma;
  }

  return result;
}

int main() {
  string str;
  cin >> str;
  vector<int> integers = parseInts(str);
  for(size_t i = 0; i < integers.size(); i++) {
    cout << integers[i] << endl;
  }

  return 0;
}
