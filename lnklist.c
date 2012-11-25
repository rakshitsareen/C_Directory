//sg
#include<stdio.h>
#include<malloc.h>
struct node {
int value;
node *next;
};

node* create_node(){
node* tmp = (node*)malloc(sizeof(node));
return tmp;
}


void insert_after(int a,node* start){
node *temp = start ;
while(temp->next != NULL && temp->value!=x){
temp = temp -> next;
}	//while ends
if(temp->next == NULL && temp -> value != x){
printf("Data Not Found. Sorry .\n");
}	//if ends
else{
node *tmp = (node*)malloc(sizeof(node));
tmp -> value = a;
tmp -> next = temp -> next;
temp -> next = tmp;
}	//else ends
}	//insert_after ends


void append(int a, node *start){
node *tmp = start;
if(start == NULL){
printf("Empty List \n");return;}
while(tmp->next != NULL){
tmp = tmp->next;
}	//while ends
node *temp = (node*)malloc(sizeof(node));
temp -> value = a;
temp ->next = NULL;
tmp -> next = temp;
}	//append ends


void insert_start(int a, node *start){

}

main(){
}
