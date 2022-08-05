#include<stdio.h>
#include <stdlib.h>
#define MAX(a,b) ((a)>(b) ? a : b)

typedef struct node
{
	int info;
	struct node *left,*right;
}NODE;

NODE* create(NODE *bnode,int x)
{
	NODE *getnode;
	if(bnode==NULL)
	{
		bnode=(NODE*) malloc(sizeof(NODE));
		bnode->info=x;
		bnode->left=bnode->right=NULL;
	}
	else if(x>bnode->info)
		bnode->right=create(bnode->right,x);
	else if(x<bnode->info)
		bnode->left=create(bnode->left,x);
	else
	{
		printf("Duplicate node\n");
		exit(0);
	}
	return(bnode);
}
void inorder(NODE *ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr->left);
		printf("%5d",ptr->info);
		inorder(ptr->right);
	}
}
void postorder(NODE *ptr)
{
	if(ptr!=NULL)
	{
		postorder(ptr->left);
		postorder(ptr->right);
		printf("%5d",ptr->info);
	}
}
void preorder(NODE *ptr)
{
	if(ptr!=NULL)
	{
		printf("%5d",ptr->info);
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

int height(NODE *cur){
	if (cur == NULL)
		return -1;
	else
		return MAX(height(cur->left),height(cur->right))+1;
}

void balancefactor(NODE *cur){
	static int x;
	if(cur){
		balancefactor(cur->left);
		x = height(cur->left)-height(cur->right);
		printf("\nNode with value %d has a balance factor of %d",cur->info,x);
		balancefactor(cur->right);
	}
}

int main()
{
	int n,x,ch,i;
	NODE *root;
	root=NULL;
	while(1)
	{
		printf("********************Output********************\n\n");
		printf("-----------Menu-----------\n");
		printf(" 1. Insert\n 2. All traversals\n 3.Show balance factor\n 4. Exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1: printf("Enter node (do not enter duplicate nodes):\n");
			scanf("%d",&x);
			root=create(root,x);
			break;
			case 2: printf("\nInorder traversal:\n");
			inorder(root);
			printf("\nPreorder traversal:\n");
			preorder(root);
			printf("\nPostorder traversal:\n");
			postorder(root);
			printf("\n\n*********************************************");
			break;
			case 3:balancefactor(root);
			break;
			case 4: exit(0);
			default:
			printf("Enter proper choice !");
		}
	}
	return 0;
}