//Making an open hash table

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct hash_tble* nodeptr;
typedef struct hash_tble
{
	int data;
	nodeptr next;

}hash_tble;

nodeptr table[100];
int opcount = 0;

nodeptr make_linked_node(int val)
{
	nodeptr temp = (nodeptr)malloc(sizeof(hash_tble));
	temp->data = val;
	temp->next = NULL;
	return temp;
}
nodeptr insert_at_tail(nodeptr first,int val)
{
	if (first->next == NULL)
	{
		first->next = make_linked_node(val);
		return first;
	}
	nodeptr temp = first->next;
	while (temp && temp->next)
		temp = temp->next;
	temp->next = make_linked_node(val);
	return first;
}
int make_hash(int arr[],int m,int n)
{
	for (int i =0;i<n;i++)
	{
		int h = arr[i]%m;
		//opcount++;
		table[h] = insert_at_tail(table[h],arr[i]);
	}
	return 0;
}


void search_in_hash(int elm,int m)
{
	int h = (elm)%m;
	nodeptr p = table[h]->next;
	while (p != NULL)
	{
		opcount++;
		if (p->data == elm){
			printf("\nElement Found!");
			return;
		}
		p = p->next;
	}
	printf("\nElement Not found!");
}
int main()
{
	int m = 10;
	int arr[] = {52,24,72,80,44,65,23,17};
	int n = 8;
	for (int i = 0;i<m;i++)
	{
		table[i] = make_linked_node(i);
	}
	make_hash(arr,m,n);
	
	search_in_hash(52,m);
	printf("\nOperation Count: %d",opcount);
	return 0;

}