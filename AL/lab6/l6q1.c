#include <stdio.h>
#include <stdlib.h>

int opcount=0;

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}*NODE;

NODE create_tree()
{
	NODE temp;
	int ele;
	printf("Enter the element to be inserted (-1 for null) : ");
	scanf("%d",&ele);
	if (ele==-1)
		return NULL;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=ele;
	printf("Enter lchild child of %d:\n",ele);
	temp->left=create_tree();
	printf("Enter rchild child of %d:\n",ele);
	temp->right=create_tree();
	return temp;
}

int countnodes(NODE header)
{
	opcount++;
	if(!header)
	{
		return 0;
	}
	return 1+countnodes(header->right)+countnodes(header->left);
}

int main()
{
	NODE header=create_tree();
	int num=countnodes(header);
	printf("The number of nodes is  : %d",num);
	printf("\n\nThe opcount  is : %d\n",opcount);
	return 0;
}