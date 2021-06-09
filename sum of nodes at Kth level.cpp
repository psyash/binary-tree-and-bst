#include <iostream>
using namespace std;
int sum = 0;
class node{
  public:
  int data;
  node* left;
  node* right;
  node(int d){
    data = d;
    left = NULL;
    right = NULL;

  }
};

void sumAtKthLevel(node* root, int k){

  if(root == NULL){
    return;
  }
  if(k==0){
    sum += root->data;
    return;
  }
  sumAtKthLevel(root->left,k-1);
  sumAtKthLevel(root->right,k-1);
}

node* insertPreorder(node* root){
  int d,c;
  cin>>d>>c;
  root = new node(d);
  if(c==0){
    return root;
  }
  if(c==1){
    root->left = insertPreorder(root->left);
    return root;
  }
  else{
  root->left = insertPreorder(root->left);
  root->right = insertPreorder(root->right);
  return root;
  }
}

int main() {
  node* root = NULL;
  root = insertPreorder(root);
  int k;
  cin>>k;
  sumAtKthLevel(root,k);
  cout<<sum<<endl;
  return 0;
}
