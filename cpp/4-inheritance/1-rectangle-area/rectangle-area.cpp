#include <iostream>

using namespace std;

class Rectangle {
protected:
  int width, height;

public:
  void read_input() {
    cin >> this->width >> this->height;
  }
  void display() {
    cout << this->width << " " << this->height << endl;
  }
};

class RectangleArea : public Rectangle {
public:
  void display() {
    cout << this->width * this->height << endl;
  }
};

int main()
{
  /*
   * Declare a RectangleArea object
   */
  RectangleArea r_area;

  /*
   * Read the width and height
   */
  r_area.read_input();

  /*
   * Print the width and height
   */
  r_area.Rectangle::display();

  /*
   * Print the area
   */
  r_area.display();

  return 0;
}
