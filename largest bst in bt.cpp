bool isBST(node *root, int minV = INT_MIN, int maxV = INT_MAX)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data >= minV && root->data <= maxV && isBST(root->left, minV, root->data) && isBST(root->right, root->data, maxV))
    {
        return true;
    }
    return false;
}

int count(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + count(root->left) + count(root->right);
}

int sizeOfMaxBST(node *root)
{
    int maxSize = 0;
    if (root == NULL)
    {
        return 0;
    }
    if (isBST(root))
    {
        maxSize = max(maxSize, count(root));
    }
    return max(maxSize, max(sizeOfMaxBST(root->left), sizeOfMaxBST(root->right)));
}