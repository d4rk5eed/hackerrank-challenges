#include <iostream>
#include <string>
#include <vector>

using namespace std;

string get_concat(vector<string> strings) {
  vector<string>::iterator it;
  string str("");

  for(it = strings.begin(); it != strings.end(); ++it){
    str += *it;
  }

  return str;
}

vector<string> get_swaps(vector<string> strings) {
  char tmp = strings[1][0];
  strings[1][0] = strings[0][0];
  strings[0][0] = tmp;

  return strings;
}

vector<string> get_sizes(vector<string> strings) {
  vector<string>::iterator it;
  vector<string> new_strings;

  for(it = strings.begin(); it != strings.end(); ++it){
    new_strings.push_back((to_string((*it).size())));
  }

  return new_strings;
}

void print_decorator(vector<string> strings) {
  for(vector<string>::iterator it = strings.begin(); it != strings.end(); ++it){
    cout << *it << " ";
  }
  cout << endl;
}

int main() {
  vector<string> arr(2);

  for(vector<string>::iterator it = arr.begin(); it != arr.end(); ++it){
    cin >> *it;
  }

  print_decorator(get_sizes(arr));
  cout << get_concat(arr) << endl;
  print_decorator(get_swaps(arr));

  return 0;
}
