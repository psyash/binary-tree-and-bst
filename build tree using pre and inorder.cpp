#include<iostream>
using namespace std;
class tree{
	public:
	int data;
	tree *left;
	tree *right;
	tree(int data)
	{
		this->data=data;
		this->left=NULL;
		this->right=NULL;

	}
};
tree * buildtree(tree * &root ,int *preorder,int * inorder,int start,int end)
{	
	if(start>end)
		return NULL;
    static int i=0;
	root=new tree(preorder[i]);
	int index=-1;
	for(int j=start;j<=end;j++)
		{
			if(inorder[j]==preorder[i])
				{
					index=j;
					break;
				}
		}
	i++;
	buildtree(root->left,preorder,inorder,start,index-1);
	buildtree(root->right,preorder,inorder,index+1,end);
	return root;
}
void print(tree *&root)
{
	if(root==NULL)
		return;
	if(root->left)
	cout<<root->left->data<<" => ";
	else
	cout<<"END => ";

	cout<<root->data;

	if(root->right)
	cout<<" <= "<<root->right->data;
	else
	cout<<" <= END";
	cout<<endl;
	print(root->left);
	print(root->right);
	return;
}
int main() {
	int n,m;
	cin>>n;
	int preorder[n];
	for(int i=0;i<n;i++)
		cin>>preorder[i];
	cin>>m;
	int inorder[m];
	for(int i=0;i<m;i++)
		cin>>inorder[i];
	tree *root=NULL;	
	buildtree(root,preorder,inorder,0,n-1);
	print(root);
	return 0;
}