#include <iostream>
#include <deque>

using namespace std;

void printKMax(int arr[], int n, int k){
  deque<int> frame(k);

  int i = 0;
  for(; i < k; i++) {
    while((!frame.empty()) && arr[frame.back()] <= arr[i]){
      frame.pop_back();
    }
    frame.push_back(i);
  }

  for(; i < n; i++) {
    cout << arr[frame.front()] << " ";
    while((!frame.empty()) && frame.front() <= i - k) {
      frame.pop_front();
    }

    while((!frame.empty()) && arr[frame.back()] <= arr[i]){
      frame.pop_back();
    }
    frame.push_back(i);
  }
  cout << arr[frame.front()];
  cout << endl;
}

int main(){
  int t;
  cin >> t;
  while(t>0) {
    int n,k;
    cin >> n >> k;
    int i;
    int arr[n];
    for(i=0;i<n;i++)
      cin >> arr[i];
    printKMax(arr, n, k);
    t--;
  }
  return 0;
}
