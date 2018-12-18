#include<bits/stdc++.h>
using namespace std;
vector<int>arr;
int i=0;
struct node
{
    int key;
    node *left, *right;
};
queue<node*>q;
node *newNode(int item)
{
    node *temp =  new node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
node* insert(node* node, int key)
{

    if (node == NULL)
    	return newNode(key);
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}
void postOrder(node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        arr.push_back(root->key);
    }
}
void sort_tree(node *root)
{
    q.push(root);
    if(!q.empty())
    {
        node *temp=q.front();
        q.pop();
        temp->key=arr[i++];
        if(temp->left!=NULL)
            q.push(temp->left);
        if(temp->right!=NULL)
            q.push(temp->right);
    }
}
int main()
{
    node *root = NULL;
    int a;
    cout<<"enter y to insert into tree"<<endl;
    char b;
    cin>>b;
    cout<<"enter  value"<<endl;
    cin>>a;
    root = insert(root, a);
    cout<<"enter y to insert into tree"<<endl;
    cin>>b;
    while(1)
    {
        if(b=='y')
        {
            cout<<"enter  value"<<endl;
            cin>>a;
            insert(root,a);
        }
        else
        {
            break;
        }
        cout<<"enter y to insert into tree"<<endl;
        cin>>b;

    }
    postOrder(root);
    sort_tree(root);
    return 0;
}
