#include <cstddef>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Node
{
public:
  int data;
  Node *next;
  Node(int d){
    data=d;
    next=NULL;
  }
};
class Solution{
public:

  Node* removeDuplicates(Node *head) {
    Node* prev, *cur = head;
    vector<int> dup_vector;
    vector<int>::iterator p;

    while(cur) {
      p = find(dup_vector.begin(), dup_vector.end(), cur->data);

      if(p != dup_vector.end()) {
        cur = remove(prev, cur);
      } else {
        dup_vector.push_back(cur->data);
        prev = cur;
        cur = cur->next;
      }
    }
    return head;
  }

  Node*  remove(Node* prev, Node* cur) {
    prev->next = cur->next;
    delete cur;
    return prev->next;
  }

  Node* insert(Node *head,int data)
  {
    Node* p=new Node(data);
    if(head==NULL){
      head=p;

    }
    else if(head->next==NULL){
      head->next=p;

    }
    else{
      Node *start=head;
      while(start->next!=NULL){
        start=start->next;
      }
      start->next=p;

    }
    return head;


  }
  void display(Node *head)
  {
    Node *start=head;
    while(start)
      {
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
  while(T-->0){
    cin>>data;
    head=mylist.insert(head,data);
  }
  head=mylist.removeDuplicates(head);

  mylist.display(head);

}
