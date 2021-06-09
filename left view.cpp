void leftViewHelper(node *root, int level, int &max_level) {
    if(root == NULL) {
        return;
    }
    if(max_level<level) {
        cout<<root->data<<" ";
        max_level = level;
    }
    leftViewHelper(root->left, level+1, max_level);
    leftViewHelper(root->right, level+1, max_level);
}

void leftView(node *root) {
    int max_level = 0;
    leftViewHelper(root, 1, max_level);
}