#include <iostream>
#include <cstddef>
#include <cassert>

using namespace std;

class Node{
public:
  int data;
  Node *left;
  Node *right;
  Node(int d){
    data = d;
    left = NULL;
    right = NULL;
  }
};
class Solution{
public:
  Node* insert(Node* root, int data) {
    if(root == NULL) {
      return new Node(data);
    }
    else {
      Node* cur;
      if(data <= root->data){
        cur = insert(root->left, data);
        root->left = cur;
      }
      else{
        cur = insert(root->right, data);
        root->right = cur;
      }

      return root;
    }
  }

  int getHeight(Node* root){
    if(root == NULL)
      return -1;
    else {
      return 1 + max(this->getHeight(root->left), this->getHeight(root->right));
    }
  }
}; //End of Solution

void test() {
  Solution* s = new Solution;
  Node* root;
  assert(s->getHeight(NULL) == -1);

  root = s->insert(NULL, 3);
  assert(s->getHeight(root) == 0);

  s->insert(root, 5);
  assert(s->getHeight(root) == 1);

  s->insert(root, 2);
  s->insert(root, 1);
  assert(s->getHeight(root) == 2);

  s->insert(root, 4);
  s->insert(root, 6);
  s->insert(root, 7);
  assert(s->getHeight(root) == 3);
}

int main() {
  Solution myTree;
  Node* root = NULL;
  int t;
  int data;

  cin >> t;

  while(t-- > 0){
    cin >> data;
    root = myTree.insert(root, data);
  }
  int height = myTree.getHeight(root);
  cout << height;

  return 0;
}
