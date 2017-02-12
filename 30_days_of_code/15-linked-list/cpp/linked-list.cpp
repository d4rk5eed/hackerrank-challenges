#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node(int d) {
    data=d;
    next=NULL;
  }
};

class Solution {
public:
  Node* insert(Node *head, int data)
  {
    if(head == NULL)
      return new Node(data);
    else {
      Node *tail = this->tail(head);
      tail->next = new Node(data);
      return head;
    }
  }

  Node* tail(Node *head)
  {
    Node *cursor = head;
    while(cursor->next)
      cursor = cursor->next;
    return cursor;
  }

  void display(Node *head)
  {
    Node *start=head;
    while(start) {
      cout<<start->data<<" ";
      start=start->next;
    }
  }
};

int main()
{
  Node* head=NULL;
  Solution mylist;
  int T,data;
  cin>>T;
  while(T-->0) {
    cin>>data;
    head=mylist.insert(head,data);
  }
  mylist.display(head);
}
