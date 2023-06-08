#include <stdio.h>
#include <stdlib.h>


typedef int element;

typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode* makeNode(element key) {
	TreeNode* node = (TreeNode*)calloc(1, sizeof(TreeNode));
	node->key = key;

	return node;
}
TreeNode *insertNode(TreeNode* root) {
	int key, left, right;

	scanf("%d %d %d", &key, &left, &right);

	root = makeNode(key);
	if (left) {
		root->left = insertNode(root->left);
	}

	if (right) {
		root->right = insertNode(root->right);
	}

	return root;
}

void exploreTree(TreeNode* root, char* cmd) {
	printf(" %d", root->key);

	if (*cmd == 'R') {
		exploreTree(root->right, cmd + 1);
	}
	if (*cmd == 'L') {
		exploreTree(root->left, cmd + 1);
	}
}

int main() {
	TreeNode* root = NULL;

	int cnt = 0;
	char cmd[101];
	scanf("%d", &cnt);

	root = insertNode(root);

	scanf("%d", &cnt);

	for (int i = 0; i < cnt; i++) {
		scanf("%s", cmd);
		exploreTree(root, cmd);
		printf("\n");
	}
	return 0;
}