void sumOfGreaterElement(node*root, int sum){
  sum = 0;
  if(root==NULL){
    return;
  }

  sumOfGreaterElement(root->right, sum);
  sum += root->data;
  root->data = sum;
  sumOfGreaterElement(root->left,sum);
}