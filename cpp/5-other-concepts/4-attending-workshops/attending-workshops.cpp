#include <iostream>
#include <vector>
#include <algorithm>

using namespace ::std;

struct Workshop {
  int start_time;
  int duration;
  int end_time;
};

struct Available_Workshops {
  vector<Workshop> workshops;
  int n;
};

Available_Workshops* initialize(int* start_time, int* duration, int n) {
  Available_Workshops* available_workshops = new Available_Workshops;
  available_workshops->n = n;

  Workshop workshops[n];

  for(auto i = 0; i < n; ++i) {
    Workshop w = Workshop();
    w.start_time = start_time[i];
    w.duration = duration[i];
    w.end_time = start_time[i] + duration[i];

    workshops[i] = w;
  }
  cout << "Generating vector started" << endl;

  available_workshops->workshops = vector<Workshop>(workshops,  workshops + sizeof(workshops)/sizeof(Workshop));
  cout << "Generating vector ended" << endl;

  return available_workshops;
}

bool compare_ends (Workshop& i, Workshop& j) { return (i.end_time <j.end_time); }

void sort_intervals(vector<Workshop>& workshops){
  cout << "Sorting started" << endl;
  sort(workshops.begin(), workshops.end(), compare_ends);
  cout << "Sorting ended" << endl;
}

int isp_solve(vector<Workshop>& workshops) {
  sort_intervals(workshops);

  int counter = 1;
  vector<Workshop>::iterator current = workshops.begin();
  vector<Workshop>::iterator it = workshops.begin();
  for(++it; it != workshops.end(); ++it) {
    if((*it).start_time >= (*current).end_time) {
      current = it;
      counter++;
    }
  }

  return counter;
}

int CalculateMaxWorkshops(Available_Workshops* ptr){

  return isp_solve(ptr->workshops);
}

int main(int argc, char *argv[]) {
  int n; // number of workshops
  cin >> n;
  // create arrays of unknown size n
  int* start_time = new int[n];
  int* duration = new int[n];

  for(int i=0; i < n; i++){
    cin >> start_time[i];
  }
  for(int i = 0; i < n; i++){
    cin >> duration[i];
  }

  Available_Workshops * ptr;
  ptr = initialize(start_time,duration, n);
  cout << CalculateMaxWorkshops(ptr) << endl;
  return 0;
}
