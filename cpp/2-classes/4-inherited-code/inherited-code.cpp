#include <iostream>
#include <string>
#include <sstream>
#include <exception>
using namespace std;

class BadLengthException: public exception {
  int len;
public:
  BadLengthException(int n): len(n) {}
  const char* what() const throw() {
    return to_string(this->len).c_str();
  }
};

bool checkUsername(string username) {
  bool isValid = true;
  int n = username.length();
  if(n < 5) {
    throw BadLengthException(n);
  }
  for(int i = 0; i < n-1; i++) {
    if(username[i] == 'w' && username[i+1] == 'w') {
      isValid = false;
    }
  }
  return isValid;
}

int main() {
  int T; cin >> T;
  while(T--) {
    string username;
    cin >> username;
    try {
      bool isValid = checkUsername(username);
      if(isValid) {
        cout << "Valid" << '\n';
      } else {
        cout << "Invalid" << '\n';
      }
    } catch (BadLengthException e) {
      cout << "Too short: " << e.what() << '\n';
    }
  }
  return 0;
}
