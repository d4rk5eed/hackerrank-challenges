#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Matrix {
public:
  typedef vector< vector<int> > _matrix;
  _matrix a;

  Matrix operator+ (const Matrix& addend){
    Matrix result;
    int sum;
    for(auto x = 0; x < this->a.size(); ++x) {
      result.a.push_back((*new vector<int>));
      for(auto y = 0; y < this->a[x].size(); ++y) {
        sum = (this->a[x][y]) + addend.a[x][y];
        result.a[x].push_back(sum);
      }
    }

    return result;
  }
};

int main () {
  int cases,k;
  cin >> cases;
  for(k=0;k<cases;k++) {
    Matrix x;
    Matrix y;
    Matrix result;
    int n,m,i,j;
    cin >> n >> m;
    for(i=0;i<n;i++) {
      vector<int> b;
      int num;
      for(j=0;j<m;j++) {
        cin >> num;
        b.push_back(num);
      }
      x.a.push_back(b);
    }
    for(i=0;i<n;i++) {
      vector<int> b;
      int num;
      for(j=0;j<m;j++) {
        cin >> num;
        b.push_back(num);
      }
      y.a.push_back(b);
    }
    result = x+y;
    for(i=0;i<n;i++) {
      for(j=0;j<m;j++) {
        cout << result.a[i][j] << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
