#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int coef;
	int expon;
	polypointer link;
} polynode;
typedef struct node *polypointer;

void attach(int coefficient,int exponent, polypointer *ptr){
	// create a node with coef = coefficiect and expon = exponent
	//and attach it to the node pointed to by ptr
	polypointer temp = (polypointer)malloc(sizeof(polynode));
	temp->coef = coefficient;
	temp->expon = exponent;
	(*ptr)->link = temp;
	*ptr = temp;
}

polypointer padd(polypointer a, polypointer b){
	//return a polynomial which is the sum of a and b 
	polypointer c, rear, temp ;
	int sum;
	rear = (polypointer)malloc(sizeof(*rear));
	c = rear;
	while(a && b){
		switch(a->expon > b->expon ? 1 : (a->expon < b->expon ? -1 : 0)){
			case -1 : attach(b->coef,b->expon,&rear);
						b=b->link;
						break ;
			case 0	: sum = a->coef + b->coef;
					if(sum) attach(sum,a->expon,&rear);
						break;
			case 1  : attach(a->coef,a->expon,&rear);
					a = a->link;
		}

		//copy the rest of the list a then list b
		for(;a;a=a->link){
			attach(a->coef,a->expon,&rear);
		}

		for(;b;b=b->link) attach(b->coef,b->expon,&rear);

		//delete the entire initial node 

			temp = c; c = c->link ; free(temp);
		return c;
	}
}

void insert(polypointer a,int coefficient, int exponent){
	polypointer temp = (polypointer)malloc(sizeof(*temp));
	temp->coef = coefficient;
	temp->expon = exponent;
	if(a){								// if a list exists then insert it after this node "a"
		temp->link = a->link;
		a->link = temp;
	}
	else {							// else this is the first node of a new list and "a" is going to be its first node.
		temp->link = NULL;
		a = temp;
	}
}

void traverse(polypointer root){
	polypointer temp = root;		// taking a temporary pointer for traversing .
	if(temp){
		printf("%d x^%d ",temp->coef,temp->expon);
		temp = temp->link;
	}
}

int main(int argc, char const *argv[])
{
	int i ;
	polypointer a,b,result;		//take two polynomial list pointers and insert elements into them and a result pointer
	for (i = 10; i > 0; ++i)
	{
		insert(a,i,i);
	}

	for (i = 10; i > 0; ++i)
	{
		insert(b,i,i);
	}

	result = padd(a,b);
	traverse(root);

	return 0;
}