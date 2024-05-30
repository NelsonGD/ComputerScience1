/* Tanvir Ahmed
CS1
This code implements doubly linked list insertions and deletion*/

#include<stdio.h>
#include<stdlib.h>

//defining the node structure
typedef struct node
{
  int data;
  struct node *prev, *next;
} node;

node* insert_end(node* head, int item)
{
	node* temp = createNode(item); 

	//if you want to insert at end then check if linked list exist, if not then this is head
	
	if(head == NULL)
	{
		temp-> prev = NULL;
		return temp; // wil update link of linked list in root function
	}else{
		node* t = head;
		
		while(t -> next) // while(t-> next != NULL)
			t = t-> next;
	}

}

node* createNode(int item)
{
	node* temp = malloc(sizeof(node));
	temp->prev = NULL;
	temp-> data = item;
	temp-> next = NULL;

	return temp;
}


node* insert_front(node *head, int item)
{
	node* temp = createNode(item);
	temp-> next = head;
	if(head != NULL)
		head -> prev = temp;

	return temp;
}

/*takes root of a linked list and insert item to the end of the list.
Returns the root of the list after insertion
*/


/*takes root of a linked list and delete the first occurance of the item from the the list.
Returns the root of the list after deletion
*/
node* DelListDoubly(node* head, int item)
{
	
}

void display(node* t)
{
	node* temp;

	if(start == NULL)
		return;

    printf("\nPrinting your link list.......");

	do
	{
		printf("%d ",t->data);
		t=t->next;
	}while(t!=NULL);
}

int main()
{
	//declare root appropriately__________ 
	node* root;
	node *t,del;
	int ch,ele,v;
	while(1)
	{
		printf("\nMenu: 1. insert at front, 2. insert at end, 3. Delete 4. exit: ");
	    scanf("%d",&ch);
		if(ch==4)
		{
			printf("\nGOOD BYE>>>>\n");
			break;
		}
		if(ch==1)
		{
			printf("\nEnter information(an integer): ");
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
		 scanf("%d",&ele);
		 root=DelListDoubly(root, ele);
		 display(root);


	  }
	}
	return 0;
}
