/* Tanvir Ahmed
This code implements some basic operation of singly linked list like inserting in the beginning and end, delete operation, and display operation
*/

#include<stdio.h>
#include<stdlib.h>
#include "main.h"

void insertToPlace(node* list, int val, int place)
{
  if(place < 1 || list == NULL)
  {
    printf("List is empty or place is not valid");
    return;
  }

  // Create newNode since you check input is valid
  node* newNode = malloc(sizeof(node));
  newNode -> data = val;
  newNode -> next = NULL;

  if(place == 1)
  {
    newNode -> next = list;
    list = newNode;
    return;
  }

  // since placement is bigger than 1 you need to find size
  node* temp = list;
  int listSize = 1;
  
  // iterate through list updating list size
  while(temp -> next != NULL && listSize < place - 1)
  {
    temp = temp -> next;
    listSize++;
  }

  newNode -> next = temp -> next;
  temp -> next = newNode;
}

node* reverse(node* head)
{
  node* before = NULL;
  node* current = head;
  node* after = NULL; 

  while(current != NULL)
  {
    after = current -> next;
    current -> next = before;
    before = current;
    current = after;
  }

  return before;
}

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
	int ch,ele,v, del, place;
	while(1)
	{
		printf("\nMenu: 1. insert at front, 2. reverse list 3. Insert to place 0. exit: ");
	    scanf("%d",&ch);
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
		  scanf("%d %d", &ele, &place);
		  insertToPlace(root, ele, place);
      display(root);

		}
	}
  return 0;
}
