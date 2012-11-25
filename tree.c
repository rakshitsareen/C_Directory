#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node* left;
	struct node* right;
};

typedef struct node* treeptr;
typedef struct node* nodeptr;

treeptr insertIntoBinaryTree(treeptr *root, int key){
	treeptr temp = NULL;
	treeptr x = *root;
	printf("inside insert\n");
	while(x!=NULL){
		printf("inside while \n");
		temp = x;
		if(key < x->data){
			x = x->left;
		}
		else {
			x = x->right;
		}
	}
	// here we have leaf node ion which we have to into temp;
	//now we insert the node into the tree
	if(!temp){
		// if tree was empty
		temp =(treeptr) malloc(sizeof(*temp));
		*root = temp;
	}
	else {
		if(key < temp->data){
			treeptr z = (treeptr)malloc(sizeof(*z));
			temp->left = z;
			z->rdata = key;
		}
		else {
			treeptr z =(treeptr) malloc(sizeof(*z));
			temp->right = z;
			z->data = key;
		}
	}
}

void inorder(treeptr root){
if(root!=NULL){
inorder(root->left);
printf("%d ",root->data);
inorder(root->right);
}
}


int main(){
struct node* tree = NULL ;
int i = 0;
for(i=0;i<11;++i)
insertIntoBinaryTree(&tree , rand()%11);

inorder(tree);
return 0;
}
