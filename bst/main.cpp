#include <iostream>
#include <stdlib.h>

using namespace std;
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node * add(struct node *root, int key)
{
   if(root== NULL)
    root=createnode(root,key)
    else if(root->left>key)
    root->left=add(root->left,key);
   else
    root->right=add(root->right,key);

   return root;

}


int main()
{
    struct node *root=NULL;
    struct node *temp;
    root=add(root,5);
    root=add(root,2);
    root=add(root,6);
    temp=root->right;
    cout<<temp->data;
    return 0;
}
