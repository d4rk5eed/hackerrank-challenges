#include <iostream>

using namespace std;

class Solution {
  class Pnode
  {
  public:
    Pnode(char c, Pnode* p = NULL, Pnode* n = NULL) {
      prev = p;
      next = n;
      value = c;
    }

    Pnode* prev;
    Pnode* next;
    char value;

  };

  Pnode* queue_tail;
  Pnode* queue_head;
  Pnode* stack;

public:
  Solution() {
    this->queue_tail = NULL;
    this->queue_head = NULL;
    this->stack = NULL;
  }
  void pushCharacter(char c) {
    Pnode* node = new Pnode(c, this->stack, NULL);
    this->stack = node;
  }
  char popCharacter() {
    char c = this->stack->value;
    Pnode* prev = this->stack;

    if(this->stack->prev != NULL)
      this->stack = this->stack->prev;

    delete prev;
    return c;
  }

  void enqueueCharacter(char c) {
    Pnode* node = new Pnode(c);

    if(this->queue_head == NULL) {
      this->queue_tail = this->queue_head = node;
    }
    else {
      this->queue_tail->next = node;
      this->queue_tail = node;
    }
  }

  char dequeueCharacter() {
    char c = this->queue_head->value;
    Pnode* prev = this->queue_head;

    if(prev->next != NULL)
      this->queue_head = prev->next;

    delete prev;
    return c;
  }
};

int main() {
  // read the string s.
  string s;
  getline(cin, s);

  // create the Solution class object p.
  Solution obj;

  // push/enqueue all the characters of string s to stack.
  for (int i = 0; i < s.length(); i++) {
    obj.pushCharacter(s[i]);
    obj.enqueueCharacter(s[i]);
  }

  bool isPalindrome = true;

  // pop the top character from stack.
  // dequeue the first character from queue.
  // compare both the characters.
  for (int i = 0; i < s.length() / 2; i++) {
    if (obj.popCharacter() != obj.dequeueCharacter()) {
      isPalindrome = false;

      break;
    }
  }

  // finally print whether string s is palindrome or not.
  if (isPalindrome) {
    cout << "The word, " << s << ", is a palindrome.";
  } else {
    cout << "The word, " << s << ", is not a palindrome.";
  }

  return 0;
}
