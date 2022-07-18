/*Apply linked list concept to perform polynomial addition*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int coeff;
	int power;
	struct node *next;
};

void createpoly(struct node *p, int hp)
{
	while(hp>=0)
	{
		printf(" Enter coefficient of x^ %d :",hp);
		scanf("%d",&p->coeff);
		p->power=hp;
		hp--;
		p->next=(struct node*)malloc(sizeof(struct node));
		p=p->next;
		p->next=NULL;
	}
}

void addpoly(struct node *poly1,struct node *poly2, struct node *poly3)
{
	while(poly1->next && poly2->next)
	{
		poly3->coeff=poly1->coeff+poly2->coeff;
		poly3->power=poly1->power;
		poly3->next=(struct node*)malloc(sizeof(struct node));
		poly3=poly3->next;
		poly1=poly1->next;
		poly2=poly2->next;
		poly3->next=NULL;
	}
}

void display(struct node *p)
{
	printf("\n The new expression is :");
	while(p->next!=NULL)
	{
		printf("%d x^%d",p->coeff,p->power);
		p=p->next;
		if (p->next!=NULL)
		{
			printf(" + ");
		}
	}
}

void main()
{
	int x;
	struct node *p1=NULL,*p2=NULL,*p3=NULL;
	p1=(struct node*)malloc(sizeof(struct node));
	p2=(struct node*)malloc(sizeof(struct node));
	p3=(struct node*)malloc(sizeof(struct node));	
	printf(" Enter the highest power of expression :");
	scanf("%d",&x);
	printf(" \nEnter values of expression 1:\n"); 
	createpoly(p1,x);
	printf(" \nEnter values of expression 2:\n");
	createpoly(p2,x);
	addpoly(p1,p2,p3);
	display(p3);
	
	
}
