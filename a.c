#include "a.h"
#include <stdio.h>

struct node
{
	int x;
	position next;
};

int IsLast(position p,list l){
	return p->next == NULL;
}

position Find(int x,list l){
	position p ;
	p = l->next;
	while(p!=NULL && p->x!=x)
		p=p->next;
	return p;
}

void Delete(int x,list l){
	position p,temp;
	p = FindPrevious(int x,list l);
	if(!IsLast(p,l)){
		temp = p->next;
		p->next = temp->next;
		free(temp);
	}

}


position FindPrevious(int x,list l){
	position p = l;
	while(p->next!=NULL && p->next->x!= x)
		p=p->next;
	return p;
}

void Insert(int x,list l,postion p){
	position temp;
	temp = malloc(sizeof(struct node));
	if(temp == NULL){
		printf("out of space");
		return ;
	}
	temp->x = x;
	temp->next = p->next;
	p->next = temp;
}

void DeleteList(list l){
	postion p ,temp;
	p = l->next;
	l->next = NULL;
	while(p!=NULL){
		temp = p->next;
		free(p);
		p=temp;
	}
}

position GoToPosition(list l, int pos){
int i ;
position p = l->next;
for(i=0;i<pos;++i)

}