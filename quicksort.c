#include<stdio.h>
#include<stdlib.h>
#define SIZE 20

int partition(int arr[] , int p , int  q);
void quicksort(int arr[] , int start , int end);
void print(int arr[]);

int main(){
  int arr[SIZE];
  int i ;

  for(i=0;i<SIZE;++i) arr[i]= rand()%20;
  print(arr);
  quicksort(arr,0,SIZE-1);
  print(arr);
  return 0;
}


void quicksort(int arr[] , int p, int r){
  int q;
  if(p<r){
    q = partition(arr,p,r);
    quicksort(arr,p,q-1);
    quicksort(arr,q+1,r);
  }
}


int partition(int arr[], int p, int r){
  int i,j,x,temp;
  x = arr[r];
  i=p-1;
  //printf("%d\n",i);
  for(j=p;j<r;++j){
    if(arr[j]<=x){
      i++;
      /*swap the two elements */
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  temp = arr[i+1];
  arr[i+1] = arr[j];
  arr[j] = temp;
  return i+1;
}

void print(int arr[]){
  int i;
  for(i=0;i<SIZE;++i){
    printf("%d, ",arr[i]);
  }
  printf("\n");
}
