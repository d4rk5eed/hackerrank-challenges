#include <iostream>
using namespace std;

int main() {

  int **array;

  int num_of_arrays, num_of_queries, local_array_size;

  int x, y;
  cin >> num_of_arrays >> num_of_queries;

  array = new int*[num_of_arrays];

  for(int cursor = 0; cursor < num_of_arrays; cursor++) {
    cin >> local_array_size;

    array[cursor] = new int[local_array_size];

    for(int local_cursor = 0; local_cursor < local_array_size; local_cursor++){
      cin >> array[cursor][local_cursor];
    }
  }

  while(num_of_queries--) {
    cin >> y >> x;
    cout << array[y][x] << endl;
  }

  return 0;
}
