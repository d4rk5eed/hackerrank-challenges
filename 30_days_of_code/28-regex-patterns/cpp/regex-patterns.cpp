#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <regex>
#include <set>

using namespace std;

void insert_name(multiset<string>& storage, const string& name, const string &email) {
  if(regex_match(email, regex("(.+)@gmail.com")))
    storage.insert(name);
}

int main() {
  multiset<string> storage;
  multiset<string>::iterator it;

  string email, name;
  int n;

  cin >> n;

  while(n--) {
    cin >> name >> email;

    insert_name(storage, name, email);
  }

  for(it = storage.begin(); it != storage.end(); it++)
    cout << *it << endl;
  return 0;
}
