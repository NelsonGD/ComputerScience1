/*
Nelson Diaz

Program implements a reverse function and insertToPlace function for linked list.
*/

#include<stdio.h>
#include<stdlib.h>
 typedef struct node{
	struct node *next;
	int data;
}node;

//this function takes an item and insert it in the linked list pointed by root.
node*  insert_front(node *root, int item)
{
	node *temp;
	//create a new node and fill-up the node
	temp= (node *) malloc(sizeof(node));
	temp->data=item;
	temp->next=NULL;
	if(root==NULL) //if there is no node in the linked list
        root=temp;
    else //there is an existing linked list, so put existing root after temp
    {
        temp->next = root; //put the existing root after temp
        root = temp; //make the temp as the root!
    }
  return root;
}

node* reverse(node* head)
{
    node* reverse_list = malloc(sizeof(node));
    reverse_list -> data = head;
    reverse_list -> next = NULL;

	node* temp;
    

}

void display(node* t)
{
  printf("\nPrinting your linked list.......");

	while(t!=NULL)
	{
		printf("%d ",t->data);
		t=t->next;
	}

}

int main()
{
	node *root=NULL; //very important line. Otherwise all function will fail
	node *t;
	int ch,ele,v, del;
	while(1)
	{
		printf("\nMenu: 1. insert at front, 2. reverse list, 3. Insert to place 4. exit: ");
	    scanf("%d",&ch);
		if(ch==4)
		{
			printf("\nGOOD BYE>>>>\n");
			break;
		}
		if(ch==1)
		{
			printf("\nEnter data(an integer): ");
			scanf("%d",&ele);
			root = insert_front(root, ele);

      display(root);

		}
		if(ch==2)
		{
			printf("\nEnter information(an integer): ");
			scanf("%d",&ele);
			root = insert_end(root, ele);
      display(root);

		}
	  if(ch==3)
	  {
		  printf("\nEnter info which u want to DELETE: ");
		  scanf("%d",&del);
		  root=DelList(root, del);
      display(root);

		}
	}
  return 0;
}
