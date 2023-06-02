#include <stdio.h>
#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef int element;

typedef struct TreeNode {
  element key;
  struct TreeNode *left, *right;
}TreeNode;

TreeNode *makeNode (element key) {
  TreeNode *node = (TreeNode*)calloc(1, sizeof(TreeNode));
  node->key = key;

  return node;
}
TreeNode *insertNode(TreeNode *root, element key) {
  if (root == NULL) {
    return makeNode(key);
  }
  if (key < root->key) {
    root->left = insertNode(root->left, key);
  }
  else if (key > root->key) {
    root->right = insertNode(root->right, key);
  }
  return root;
}

void preOrder (TreeNode * root) {
  if (root){
    printf("%d ", root->key);
    preOrder(root->left);
    preOrder(root->right);
  }
}

int getNodeCount (TreeNode *root) {
  int count = 0;
  if (root != NULL) {
    count = 1 + getNodeCount(root->left) + getNodeCount(root->right);
  }

  return count;
}

TreeNode *minValueNode (TreeNode *root) {
  TreeNode *p = root;
  while (p->left) {
    p = p->left;
  }
  return p;
}

TreeNode *deleteNode (TreeNode *root, element key) {
  if (root == NULL){
    return NULL;
  }
  if (key < root->key){
    root->left = deleteNode(root->left, key);
  }
  else if (key > root->key){
    root->right = deleteNode(root->right, key);
  }
  else {
    if (root->left == NULL) {
      TreeNode *temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL) {
      TreeNode *temp = root->left;
      free(root);
      return temp;
    }
    else { //후위계승자를 찾음 / 주로 오른쪽 노드의 왼쪽 끝을 넣음
      TreeNode *temp = minValueNode(root->right);
      root->key = temp->key;
      root->right = deleteNode(root->right, temp->key);
    }
  }
  return root;
}

int main(){
  TreeNode *root = NULL;

  root = insertNode(root, 35);  root = insertNode(root,68);
  root = insertNode(root, 99);  root = insertNode(root,18);
  root = insertNode(root, 7);  root = insertNode(root,3);
  root = insertNode(root, 12);  root = insertNode(root,26);
  root = insertNode(root, 22);  root = insertNode(root,30);

  preOrder(root); printf("\n");

  // printf("Node Count : %d, Leaf Node Count : %d\n", getNodeCount(root), getLeafNodeCount(root));

  deleteNode(root, 30); preOrder(root); printf("\n");
  deleteNode(root, 18); preOrder(root); printf("\n");
  

  return 0;
}