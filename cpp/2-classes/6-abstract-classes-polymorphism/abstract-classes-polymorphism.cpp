#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
  Node* next;
  Node* prev;
  int value;
  int key;
  Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
  Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{

protected:
  map<int,Node*> mp; //map the key to the node in the linked list
  int cp;  //capacity
  Node* tail; // double linked list tail pointer
  Node* head; // double linked list head pointer
  virtual void set(int, int) = 0; //set function
  virtual int get(int) = 0; //get function

};

class LRUCache : Cache {
  int size;

  void do_friends(Node* left, Node* right) {
    if(left) left->next = right;
    if(right) right->prev = left;
  }

  void move_to_head(Node* node_ptr) {
    do_friends(node_ptr->prev, node_ptr->next);
    if(node_ptr->prev) this->tail = node_ptr->prev;
    node_ptr->prev = NULL;
    node_ptr->next = this->head;
    this->head->prev = node_ptr;
    this->head = node_ptr;
  }

public:
  LRUCache(int capacity){
    this->cp = capacity;
    this->size = 0;
  }

  void set(int key, int val) {
    Node* node_ptr = this->mp[key];
    if(node_ptr) {
      node_ptr->value = val;
      move_to_head(node_ptr);
      return;
    }
    if(this->size == 0) {
      node_ptr = new Node(key, val);
      this->mp[key] = node_ptr;
      this->tail = this->head = node_ptr;
      this->size++;
    }
    else if(this->size < this->cp) {
      node_ptr = new Node(NULL, this->head, key, val);
      this->head->prev = node_ptr;
      this->head = node_ptr;
      this->mp[key] = node_ptr;
      this->size++;
    }
    else {
      node_ptr = new Node(NULL, this->head, key, val);
      this->head->prev = node_ptr;
      this->head = node_ptr;
      this->mp[key] = node_ptr;
      this->mp.erase(this->tail->key);
      this->tail = this->tail->prev;
      delete this->tail->next;
      this->tail->next = NULL;
    }
  }

  int get(int key) {
    try {
      Node* node_ptr = mp.at(key);

      move_to_head(node_ptr);
      return node_ptr->value;
    }
    catch(out_of_range) {
      return -1;
    }
  }
};

int main() {
  int n, capacity,i;
  cin >> n >> capacity;
  LRUCache l(capacity);
  for(i=0;i<n;i++) {
    string command;
    cin >> command;
    if(command == "get") {
      int key;
      cin >> key;
      cout << l.get(key) << endl;
    }
    else if(command == "set") {
      int key, value;
      cin >> key >> value;
      l.set(key,value);
    }
  }
  return 0;
}
