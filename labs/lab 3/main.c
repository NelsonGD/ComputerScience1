/*
Nelson Diaz

Program implements a reverse function and insertToPlace function for linked list.
*/

#include "main.h",
#include <stdio.h>
#include <stdlib.h>

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
	node* reversed_list = NULL; // Will be new head
	node* current = head; // Beginnning of current list
	node* next = NULL; // Will store the node next to 'current'

	while(current != NULL)
	{
		next = current -> next;
		current -> next = reversed_list;
		reversed_list = current;
		current = next;
	}
	return reversed_list; // returning the new head of the list
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

void insertToPlace(node* head, int val, int place)
{
	if(place <= 1 || head == NULL){
		printf("List is empty or place is not valid");
	}else{
		node* newValue = malloc(sizeof(node));
		if(newValue == NULL)
		{
			printf("Malloc failed for newValue");
			exit(1);
		}
		newValue -> data = val;
		newValue -> next = NULL;

		// getting list pointer and variable declaration
		node* current = head;
		node* prev = NULL;
		int counter = 1; // place is always bigger than 1

		// iterating until prev of insertion point
		while(current != NULL && counter < place)
		{
			prev = current;
			current = current -> next;
			counter++;
		}

		// if position bigger than list size place newValue at the end
		if(current == NULL && prev != NULL)
		{
			prev -> next = newValue;
		}
		else if(prev != NULL)
		{
			prev -> next = newValue;
			newValue -> next = current;
		}
	}
}

int main()
{
	node *root=NULL; //very important line. Otherwise all function will fail
	node *t;
	int ch, ele, v, val, place;
	while(1)
	{
		printf("\nMenu: 1. insert at front, 2. reverse list 3. Insert to place 0. exit: ");
	    scanf("%d", &ch);
		if(ch==0)
		{
			printf("\nGOOD BYE>>>>\n");
			break;
		}
		if(ch==1)
		{
			printf("\nEnter data(an integer): ");
			scanf("%d", &ele);
			root = insert_front(root, ele);
      		display(root);

		}
		if(ch==2)
		{
			printf("\nList reversed.");
			root = reverse(root);
			display(root);
		}
	    if(ch==3)
	  	{
		  printf("\nEnter data (an integer) and place (>1) separated by space: ");
		  scanf("%d %d", &val, &place);
		  insertToPlace(root, val, place);
		  display(root);
		}
	}
  return 0;
}
