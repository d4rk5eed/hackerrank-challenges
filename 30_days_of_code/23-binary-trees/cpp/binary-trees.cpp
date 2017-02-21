#include <iostream>
#include <cstddef>
#include <queue>
#include <string>
#include <cstdlib>
#include <cassert>

using namespace std;
class Node{
public:
  int data;
  Node *left,*right;
  Node(int d){
    data=d;
    left=right=NULL;
  }
};
class Solution{

public:
  queue<int> test_q;
  Node* insert(Node* root, int data){
    if(root==NULL){
      return new Node(data);
    }
    else{
      Node* cur;
      if(data<=root->data){
        cur=insert(root->left,data);
        root->left=cur;
      }
      else{
        cur=insert(root->right,data);
        root->right=cur;
      }
      return root;
    }
  }

  void levelOrder(Node * root){
    queue<Node*> traversal_queue;
    Node* tree;

    if(root != NULL) {
      traversal_queue.push(root);

      while(traversal_queue.size()) {
        tree = traversal_queue.front();
        traversal_queue.pop();

        cout << tree->data << " ";

        if(tree->left)
          traversal_queue.push(tree->left);

        if(tree->right)
          traversal_queue.push(tree->right);
      }
    }
  }
};//End of Solution
int main(){
  Solution myTree;
  Node* root=NULL;
  int T,data;
  cin>>T;
  while(T-->0){
    cin>>data;
    root= myTree.insert(root,data);
  }
  myTree.levelOrder(root);
  return 0;
}
