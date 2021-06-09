void rightViewHelper(node *root, int level, int &max_level) {
    if(root == NULL) {
        return;
    }
    if(max_level<level) {
        cout<<root->data<<" ";
        max_level = level;
    }
    rightViewHelper(root->right, level+1, max_level);
    rightViewHelper(root->left, level+1, max_level);
}

void rightView(node *root) {
    int max_level = 0;
    rightViewHelper(root, 1, max_level);
}