/*
struct node
{
    int data;
    node* left;
    node* right;
};

*/
void printleft(node * root)
{
    if(root == NULL)
        return;
    printleft(root->left);
    cout << root->data << " ";
}

void printright(node * root)
{
    if(root == NULL)
        return;
    cout << root->data << " ";
    printright(root->right);
}

void top_view(node * root)
{
    if(root == NULL)
        return;
    printleft(root->left);
    cout << root->data << " ";
    printright(root->right);
}