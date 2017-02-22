#include <cmath>
#include <cstdio>
#include <map>
#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
  map<string, int> container;
  map<string,int>::iterator p;
  int n, q, val;
  string name;

  cin >> n;
  while(n--) {
    cin >> q;
    switch(q) {
    case 1:
      cin >> name >> val;
      p = container.find(name);
      if(p!=container.end())
        container[name] += val;
      else
        container.insert(make_pair(name, val));
      break;
    case 2:
      cin >> name;
      container.erase(name);
      break;
    case 3:
      cin >> name;
      p = container.find(name);
      cout << (p!=container.end() ? p->second : 0) << endl;
    }
  }
  return 0;
}
