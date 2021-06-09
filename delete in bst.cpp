#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

//Accepts the old root node & data and returns the new root node
node *insertInBST(node *root, int data)
{
    //Base Case
    if (root == NULL)
    {
        return new node(data);
    }
    //Rec Case - Insert in the Subtree and Update Pointers
    if (data <= root->data)
    {
        root->left = insertInBST(root->left, data);
    }
    else
    {
        root->right = insertInBST(root->right, data);
    }
    return root;
}


node* deleteFromBST(node*root,int data){
  //Base case
  if(root==NULL){
    return new node(data) ;
  }
  //Rec case
  else if(data <= root->data){
    root->left = deleteFromBST(root->left,data);
    return root;
  }
  else if(data ==root->data){
  //0 child
  if(root->left == NULL and root->right == NULL){
    delete root;
    return NULL;
  }
  //1 child
  if(root->left!=NULL and root->right==NULL){
    node*temp = root->left;
    delete root
    return temp;
  }
  if (root->right != NULL && root->left == NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
  //2 child
  
    node*replace = root->right;
    while(replace->left!=NULL){
      replace  = replace->left;
    }
    root->data = replace->data;
    root->right = deleteFromBST(root->right,replace->data);
    return root;
  }
  else{
    root->right = deleteFromBST(root->right,data);
    return root;
  }
}

void printPreOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

int main()
{
    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        int n;
        cin >> n;
        node *root = NULL;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            root = insertInBST(root, x);
        }

        int m;
        cin >> m;

        while (m--)
        {
            int temp;
            cin >> temp;
            root = deleteInBST(root, temp);
        }

        printPreOrder(root);
        cout << endl;
    }

    return 0;
}