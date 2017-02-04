#include <vector>
#include <iostream>

using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> arr(n);
  vector<int>::iterator it;
  vector<int>::reverse_iterator rit;

  for(it = arr.begin(); it != arr.end(); it++){
    cin >> *it;
  }

  for(rit = arr.rbegin(); rit != arr.rend(); rit++){
    cout << *rit << " ";
  }
  cout << endl;
  return 0;
}
