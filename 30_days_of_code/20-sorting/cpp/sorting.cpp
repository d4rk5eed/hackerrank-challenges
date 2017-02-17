#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void make_swap(vector<int>::iterator a, vector<int>::iterator b) {
  int t = *a;
  *a = *b;
  *b = t;
};

int main() {
  int n, count = 0;
  vector<int> arr;
  bool continue_sort;

  cin >> n;

  arr = vector<int>(n);

  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  do {
    continue_sort = false;
    for(vector<int>::iterator it = arr.begin(); it != arr.end() - 1; it++) {
      if(*it > *(it + 1)) {
        make_swap(it, it+1);
        count++;
        continue_sort = true;
      }
    }
  } while(continue_sort);

  cout << "Array is sorted in " << count << " swaps." << endl;
  cout << "First Element: " << *arr.begin() << endl;
  cout << "Last Element: " << *(arr.end()-1) << endl;

  return 0;
}
