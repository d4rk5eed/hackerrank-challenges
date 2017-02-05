#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
  int n;
  unordered_map<string, string> umap;
  string name, phone;

  cin >> n;

  while(n--) {
    cin >> name >> phone;

    umap.insert(make_pair(name, phone));
  }

  while(cin >> name) {
    if(umap.find(name) != umap.end()) {
      cout << name << "=" << umap[name] << endl;
    } else {
      cout << "Not found" << endl;
    }
  }
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  return 0;
}
