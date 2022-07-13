#include<stdio.h>
#include<stdlib.h>

struct node
{
	int coefficient;
	int power;
	struct node *next;
};

struct node *p1=NULL,*p2=NULL,*p3=NULL;

void cstruct(struct node *p)
{
	int size,i;
	printf("Enter the highest term :");
	scanf("%d",&size);
	for(i=size;i>0;i--)
	{
		printf("Enter coefficient of %d term :",i);
		scanf("%d",&p->coefficient);
		printf("Enter power of %d term :",i);
		scanf("%d",&p->power);
		p->next=(struct node*)malloc(sizeof(struct node));
		p=p->next;
		p->next =NULL;
	}
}

void input(struct node *p)
{
	p3->power=p->power;
	p3->coefficient=p->coefficient;
	p=p->next;
}

void add(struct node *p1,struct node *p2,struct node *p3)
{
	while(p1->next && p2 ->next)
	{	
		if(p1->power>p2->power)
		{	
			input(p1);
		}
		
		else if(p1->power>p2->power)
		{
			input(p2);
		}
		
		else
		{
			p3->power=p1->power;
			p3->coefficient=p1->coefficient + p2->coefficient;
			p1=p1->next;
			p2=p2->next;
		}
		
		p3->next=(struct node *)malloc(sizeof(struct node));
		p3=p3->next;
		p3->next=NULL;
	}
	
	while(p1->next || p2->next)
	{
		if(p1->next)
		{
			input(p1);
		}
		
		if(p2->next)
		{
			input(p2);
		}
		
		p3->next=(struct node *)malloc(sizeof(struct node));
		p3=p3->next;
		p3->next=NULL;
	}
}

void display(struct node *p)
{	
		while(p->next!=NULL)
		{
			printf(" %dx^%d ",p->coefficient,p->power);
			p=p->next;
			if (p->next!=NULL)
				printf("+");
		}
}	
		
void main()
{
	p1=(struct node*)malloc(sizeof(struct node));
	p2=(struct node*)malloc(sizeof(struct node));
	p3=(struct node*)malloc(sizeof(struct node));
	
	printf("\nPolynomial expression 1 \n");
	cstruct(p1);
	
	printf("Polynomial expression 1:   ");
	display(p1);
	printf("\n");

	printf("\nPolynomial expression 2 \n");
	cstruct(p2);
	printf("Polynomial expression 2:   ");
	display(p2);
	printf("\n");

	add(p1,p2,p3); 
	printf("\nSum is:   ");
	display(p3); 
	printf("\n");               		
           
}
