#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

//
//		  15
//	   4		 20
//    1	      16  25
TreeNode n1 = { 1,  NULL, NULL };
TreeNode n2 = { 4,  &n1,  NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3,  &n4 };
TreeNode n6 = { 15, &n2,  &n5 };
TreeNode* root = &n6;

#define SIZE 100
int top = -1;
TreeNode* stack[SIZE];

void push(TreeNode* p)
{
	if (top < SIZE - 1 && p != NULL)
		stack[++top] = p;
}

TreeNode* pop()
{
	TreeNode* p = NULL;
	if (top >= 0)
		p = stack[top--];
	return p;
}

void inorder_iter(TreeNode * root)
{
	while (1) {
		for (; root; root = root->left)
			push(root);
		root = pop();
		if (!root) break;
		printf("[%d] ", root->data);
		root = root->right;
	}
}

void preorder_iter(TreeNode* root)
{
	push(root);
	while (1) {
		root = pop();
		if (!root) break;
		printf("[%d] ", root->data);
		push(root->right);
		push(root->left);
	}
}

void postorder_iter(TreeNode * root)
{
	while (1) {
		do {
			if (root->data != NULL && root != NULL) {
				push(root);
				root = root->left;
			}
			else { break; }
		} while (root != NULL);
		root = pop();
		if (!root) break;
		if (root->right != NULL) {
			if (root->right->data == NULL) {
				printf("[%d] ", root->data);
				root->data = NULL;
			}
			else {
				push(root);
				root = root->right;
			}
		}
		else {
			printf("[%d] ", root->data);
			root->data = NULL;
		}
	}
}
	
int main(void)
{	
	printf("중위 순회=");
	inorder_iter(root);
	printf("\n");
	printf("전위 순회=");
	preorder_iter(root);
	printf("\n");
	printf("후위 순회=");
	postorder_iter(root);
	printf("\n");
	return 0;
}