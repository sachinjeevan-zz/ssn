#include<stdio.h>
#include<stdlib.h>
struct Node
{
    struct Node* left;
    int data;
    struct Node* right;
};
struct Node* createNode(int ele)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = ele;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct Node* insertNode(struct Node* root, int ele)
{
    
        if(root==NULL)
        {
            return createNode(ele);
        }
        while(1)
        {
            if(ele < root->data && root->left!=NULL)
            {
                root = root->left;
            }
            else if( ele < root->data && root->left==NULL)
            {
                root->left = createNode(ele);
                return root->left;
            }
            else if(ele>root->data && root->right!=NULL)
            {
                root = root->right;
            }
            else if(ele>root->data && root->right==NULL)
            {
                root->right = createNode(ele);
                return root->right;
            }
        }
    
}
struct Node* insertNodeR(struct Node* root, int ele)
{
    if(root == NULL)
    {
        return createNode(ele);
    }
    else if( ele < root->data ) 
    {
        root->left = insertNodeR(root->left, ele);
    }
    else if( ele > root->data )
    {
        root->right = insertNodeR(root->right, ele);
    }
    return root;
}
void inorder(struct Node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
int main()
{
    struct Node* root = NULL;
    root = insertNodeR(root,100);
    insertNodeR(root,180);
    insertNodeR(root,40);
    insertNodeR(root,80);
    insertNodeR(root,120);
    insertNodeR(root,20);
    inorder(root);

}