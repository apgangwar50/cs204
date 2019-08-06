#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include<math.h>
#include <string.h>

using namespace std;
struct node
{
	int x;
	int y;
    struct node* next;
};

void AddFirst(int x1, int y1,struct node** head)
{
     struct node* new_node = (struct node*) malloc(sizeof(struct node));
     new_node->x  = x1;
     new_node->y  = y1;
     new_node->next = (*head);
     (*head) = new_node;
}

int DelFirst(node* &head_ref)
{
    if(head_ref == NULL)
       return -1 ;
    node *front = head_ref;
    head_ref = head_ref->next;
    front->next = NULL;

    if(front == head_ref)
        head_ref = NULL;

    free(front);
    return 0;
}

int Del(int b, int c, struct node** head)
{
    struct node* temp = *head, *prev;

    if (temp != NULL && temp->x == b && temp->y == c)
    {
        *head = temp->next;
        free(temp);
        return 0;
    }

    while (temp != NULL && temp->x != b && temp->y != c)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    	{
    		return -1;
    	}

    prev->next = temp->next;

    free(temp);
    return 0;
}

string Search(int a, int b,node* &head)
{
		if(head == NULL)
        return "False";
		node *cursor = head;
    	while(cursor!=NULL)
    	{
       		 if(cursor->x == a && cursor->y == b)
       		 {
       		 	return "True";
       		 }
          	cursor = cursor->next;
  	 	}
   		return "False";
}

void Search(double d,node* &head)
{
	if(head == NULL)
        return ;
		node *cursor = head;
    	while(cursor!=NULL)
    	{
       		int i = cursor->x;
       		int j = cursor->y;
       		double dis = sqrt((i*i)+(j*j));

       		if(dis<=d)
       			std::cout<<"( "<<cursor->x<<" , "<<cursor->y<<" ) ";

          	cursor = cursor->next;
  	 	}
  	 	cout<<endl;
}

int Length(struct node* head)
{
	int count = 0;
    node* current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}


int main()
{
	node *head_ref = NULL;

	int terms;
	std::cin>>terms;
	int len[10000];
	for(int i=0; i<terms; i++)
	{
	int a;
	int b,c;
	double d;
	std::cin>>a;

	if(a==1)
		{
			std::cin>>b>>c;
			AddFirst(b,c, &head_ref);
		}

	if(a==2)
		{
			cout<<DelFirst(head_ref)<<endl;
		}

	if(a==3)
		{
			std::cin>>b>>c;
			cout<<Del(b,c,&head_ref)<<endl;
		}

	if(a==4)
		{
			std::cin>>d;
			Search(d,head_ref);
		}

	if(a==5)
		{
			std::cin>>b>>c;
			cout<<Search(b,c,head_ref)<<"\n";
		}

	if(a==6)
		{
			std::cout<<Length(head_ref)<<"\n";
		}
	}

return 0;
}
