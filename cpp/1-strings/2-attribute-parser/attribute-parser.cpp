#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Parser {
  string current_tag;
  string current_attr;
  string current_attr_value;
  int current_state;

  vector<string> tag_path;
  unordered_map<string, string> umap;


  static const int IDLE = 0;
  static const int OPEN_TAG = 1;
  static const int CLOSE_TAG= 2;
  static const int ATTR = 3;
  static const int ATTR_VALUE = 4;

  void state_idle(char c) {
    if(c == '<')
      this->current_state = OPEN_TAG;
  }
  void state_open_tag(char c) {
    if(c == '/')
      this->current_state = CLOSE_TAG;
    else if(c == ' '){
      this->tag_path.push_back(this->current_tag);
      this->current_tag = "";
      this->current_state = ATTR;
    }
    else if(c == '>'){
      this->tag_path.push_back(this->current_tag);
      this->current_tag = "";
      this->current_state = IDLE;
    }
    else{
      this->current_tag += c;
      this->current_state = OPEN_TAG;
    }
  }

  void state_close_tag(char c) {
    if(c == '>'){
      this->tag_path.pop_back();
      this->current_state = IDLE;
    }
  }

  void state_attr(char c){
    if(c == ' ' || c == '=')
      this->current_state = ATTR;
    else if(c == '"')
      this->current_state = ATTR_VALUE;
    else if(c == '>')
      this->current_state = IDLE;
    else{
      this->current_attr += c;
      this->current_state = ATTR;
    }
  }

  void state_attr_value(char c) {
    string key;
    if(c == '"'){
      key = this->path_to_string() + "~" + this->current_attr;
      this->umap.insert(make_pair(key, this->current_attr_value));
      this->current_attr = "";
      this->current_attr_value = "";
      this->current_state = ATTR;
    }
    else if(c == ' ')
      this->current_state = ATTR;

    else{
      this->current_attr_value += c;
      this->current_state = ATTR_VALUE;
    }
  }

  string path_to_string() {
    string path = "";
    for(string s : tag_path) {
      path += s + '.';
    };
    return path.substr(0, path.size() - 1);
  }
public:
  Parser() {
    this->current_state = IDLE;
    this->current_tag = "";
    this->current_attr = "";
    this->current_attr_value = "";
  }

  string search(string q) {
    if(this->umap.find(q) != this->umap.end()) {
      return  this->umap[q];
    } else {
      return "Not Found!";
    }
  }

  void run(string input) {
    for( char c : input) {
      switch(this->current_state) {
      case IDLE:
        state_idle(c);
        break;
      case OPEN_TAG:
        state_open_tag(c);
        break;
      case CLOSE_TAG:
        state_close_tag(c);
        break;
      case ATTR:
        state_attr(c);
        break;
      case ATTR_VALUE:
        state_attr_value(c);
      }
      //cout << this->current_state << endl;
    }
  }
};

int main() {
  string s, body = "", query;
  int lines, queries;

  cin >> lines >> queries;

  for(;lines+1; lines--){
    getline(cin, s);
    body += s;
  }
  Parser* p = new Parser();
  p->run(body);
  for(;queries; queries--){
    cin >> query;
    cout << p->search(query) << endl;
  }

  return 0;
}
