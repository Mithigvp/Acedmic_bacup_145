#include<stdio.h>
#include<stdlib.h>
#define size 5

int q[size];

void insert(int [],int,int *,int *);
void deleteq(int [],int,int *,int *);
void display(int [],int *,int *);


void main()
{
	int ch,val;

	while(1)
	{
	
		printf("\n --------Circular Queue Menu--------\n");
		printf("1.insert \n2.delete \n3.display\n4.exit");
		printf("\n Enter Your Choice:");
		scanf("%d",&ch);
		switch(ch)
		{
		
			case 1:
					printf("\n Enter Value In Queue:");
					scanf("%d",&val);

					insert(q,val,front,rear);
					break;

			case 2:
					printf("\n Enter Index To Delete Value");
					scanf("%d",&r);

					deleteq(q,front,rear,r);
					break;

			case 3:
					display(q,front,rear);
					break;
			case 4:
					exit();
					break;
			default:

				printf("\n Invalid choice..");
				break;
		}
	}
}

void insert(int val,int q[size],int *front,int *rear)
{
	*front=-1;
	*rear=-1;

	if(front==-1 && rear==-1)
	{
		printf("\n Circular Queue Is Full..\n");
	}
	 
	
	front=front+1;

	rear=front+1;

	q[front]=value;
	

}
void deletecq(int q[size],int front,int rear)
{
	int i;
	if(front==-1 && rear==-1)
	{
		printf("\nQueue Is Empty");
	}
	for(i=0;i<size-1;i++)
	{
		if(q[i]==r)
		{
			free(q[rear]);

		}
		else
		{
			printf("\n Invalid Index ");
		}
		
	}

	printf("\n Element Deleted Successfully..");

}
void display(int q[size],int front,int rear)
{
	if(front==-1 && rear==-1)
	{
		printf("\nQueue Is Empty");
	}
	while(q[size-1]!=q[0])
	{
		printf("%d",q[i]);
		front=front+1;
	}
}
