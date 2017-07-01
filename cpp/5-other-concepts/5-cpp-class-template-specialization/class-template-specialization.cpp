#include <iostream>
#include <cassert>
#include <string>

using namespace std;
enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template<typename T> struct Traits;

template<>
struct Traits<Fruit>{
  static string name(unsigned long i){
    string f[] = {"apple", "orange", "pear"};
    if(i >= sizeof(f)/sizeof(*f))
      return "unknown";
    return f[i];
  }
};

template<>
struct Traits<Color>{
  static string name(unsigned long i){
    string c[] = { "red", "green", "orange" };
    if(i >= sizeof(c)/sizeof(*c))
      return "unknown";
    return c[i];
  }
};


int main()
{
  int t = 0; std::cin >> t;

  for (int i=0; i!=t; ++i) {
    int index1; std::cin >> index1;
    int index2; std::cin >> index2;
    cout << Traits<Color>::name(index1) << " ";
    cout << Traits<Fruit>::name(index2) << "\n";
  }
}
