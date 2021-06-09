#include<iostream>
using namespace std;


class node{
public:
	int data;
	node* left;
	node* right;

	node(int data){
		this->data = data;
		this->left = NULL;
		this->right =NULL;
	}
};

node*buildtree(string s)
{
    if(s=="true")
    {
        int d;
        cin>>d;
        node*root=new node(d);

        string l;
        cin>>l;

        if(l=="true")
        {
            root->left=buildtree(l);  }

        string r;
        cin>>r;

        if(r=="true")
        {
            root->right=buildtree(r);
        }
        return root;
    }
    return NULL;
}

int height(node* root)  
{  
    if (root == NULL)  
        return 0;  
    else
    {  
        /* compute the height of each subtree */
        int lheight = height(root->left);  
        int rheight = height(root->right);  
  
        /* use the larger one */
        if (lheight > rheight)  
            return(lheight + 1);  
        else return(rheight + 1);  
    }  
} 

void printlevelorder(node*root, int level){
  if(root==NULL){
    return;
  }
  if(level == 1){
    cout<<root->data<<" ";
  }
  if(level >1){
    printlevelorder(root->left, level-1);
    printlevelorder(root->right, level-1);
  }
}
void printlevelorder2(node*root, int level){
  if(root==NULL){
    return;
  }
  if(level == 1){
    cout<<root->data<<" ";
  }
  if(level >1){
    printlevelorder2(root->right, level-1);
    printlevelorder2(root->left, level-1);
  }
}

void printZigZag(node*root){
  if(root==NULL){
    return;
  }
  int h = height(root);
  for(int i=1;i<=h;i++){
    if(i%2 != 0){
      printlevelorder(root,i);
    }
    else{
      printlevelorder2(root,i);
    }
  }
}

int main(){

 node*root=NULL;

    root=buildtree("true");
    printlevelorder(root);

    return 0;
}


