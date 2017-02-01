#include <iostream>
using namespace std;


int main() {
  int size;
  cin >> size;
  int arr[size];
  for(int i_arr = 0; i_arr < size; i_arr++) {
    cin >> arr[i_arr];
  }

  for(int i_arr = size-1; i_arr >= 0; i_arr--) {
    cout << arr[i_arr] << " ";
  }
  cout << endl;
  return 0;
}
