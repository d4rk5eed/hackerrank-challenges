#include <string>
#include <iostream>
#include <numeric>
#include <functional>
using namespace std;

class Person {

protected:
  string name;
  unsigned int age;

public:
  virtual void getdata() = 0;
  virtual void putdata() = 0;
};

class Professor: public Person {
protected:
  unsigned int publications;
  static unsigned int auto_id;
  unsigned int cur_id;

public:
  Professor() { this->cur_id = ++Professor::auto_id; }
  void getdata() {
    cin >> name >> age >> publications;
  }

  void putdata() {
    cout << name << " " << age << " " << publications << " " << cur_id << endl;
  }
};
unsigned int Professor::auto_id = 0;

class Student: public Person {
protected:
  unsigned int marks[6];
  static unsigned int auto_id;
  unsigned int cur_id;

public:
  Student() { this->cur_id = ++Student::auto_id; }
  void getdata(){
    cin >> name >> age;
    for(int s = 0; s < 6; s++)
      cin >> marks[s];
  }

  void putdata() {
    cout << name << " " << age << " " << accumulate(marks, marks+6, 0, std::plus<int>()) << " " <<  cur_id << endl;
  }
};
unsigned int Student::auto_id = 0;


int main(){

  int n, val;
  cin>>n; //The number of objects that is going to be created.
  Person *per[n];

  for(int i = 0;i < n;i++){

    cin>>val;
    if(val == 1){
      // If val is 1 current object is of type Professor
      per[i] = new Professor;

    }
    else per[i] = new Student; // Else the current object is of type Student

    per[i]->getdata(); // Get the data from the user.

  }

  for(int i=0;i<n;i++)
    per[i]->putdata(); // Print the required output for each object.

  return 0;

}
