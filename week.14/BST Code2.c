#include <stdio.h>
#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef int element;

typedef struct TreeNode
{
    element key;
    struct TreeNode *left, *right;
}TreeNode;

TreeNode* makeNode(element key)
{
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->key = key;
    node->left = node->right = NULL;
    
    return node;
}

TreeNode* findNode(TreeNode* root, element key)
{
    TreeNode *p = root;
    
    if(root == NULL)
        return NULL;
        
    if(root->key == key)
        return root;
        
    p = findNode(root->left, key);
    if(p)
        return p;
        
    return findNode(root->right, key);    
}

void insertNode(TreeNode* root, element key, int left, int right)
{
    TreeNode *p = findNode(root, key);
    if(left != 0)
        p->left = makeNode(left);
    if(right != 0)
        p->right = makeNode(right);
}

TreeNode* makeTree()
{
    int n, key, left, right;
    TreeNode* root;
    
    scanf("%d", &n);
    scanf("%d %d %d", &key, &left, &right);
    
    root = makeNode(key);
    root->left = makeNode(left);
    root->right = makeNode(right);
    
    for(int i = 1; i < n; i++)
    {
        scanf("%d %d %d", &key, &left, &right);
        insertNode(root, key, left, right);
    }
    return root;
}

void preOrder(TreeNode* root)
{
    if(root)
    {
        printf("[%d] ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    TreeNode* root = makeTree();
    preOrder(root); printf("\n");
    

    return 0;
}









