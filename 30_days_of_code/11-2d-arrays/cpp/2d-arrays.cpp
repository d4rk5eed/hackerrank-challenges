#include <vector>
#include <iostream>
#include <climits>
using namespace std;

int hourglass(vector< vector<int> > arr, int y, int x) {
  return arr[y][x] + arr[y][x+1] + arr[y][x+2] + arr[y+1][x+1] + arr[y+2][x] + arr[y+2][x+1] + arr[y+2][x+2];
}

int main(){
  vector< vector<int> > arr(6,vector<int>(6));
  for(int arr_i = 0;arr_i < 6;arr_i++){
    for(int arr_j = 0;arr_j < 6;arr_j++){
      cin >> arr[arr_i][arr_j];
    }
  }

  int max = INT_MIN;
  for(int y = 0; y < 4; y++) {
    for(int x = 0; x < 4; x++) {
      max =( hourglass(arr, y, x) > max ? hourglass(arr, y, x) : max);
    }
  }
  cout << max << endl;
  return 0;
}
