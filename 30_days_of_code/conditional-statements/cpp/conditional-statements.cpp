#include <iostream>
using namespace std;

int main(){
  int N;
  cin >> N;

  // If  is odd, print Weird
  if((N & 1) == 1)
    cout << "Weird" << endl;
  //   If  is even and in the inclusive range of 2 to 5, print Not Weird
  else if(N >= 2 && N <= 5)
    cout << "Not Weird" << endl;
  //   If  is even and in the inclusive range of  6 to 20, print Weird
  else if(N >= 6 && N <= 20)
    cout << "Weird" << endl;
  //   If  is even and greater than 20, print Not Weird
  else if(N > 20)
    cout << "Not Weird" << endl;


  return 0;
}
