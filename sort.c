#include<stdio.h>
#include<string.h>
#define MAXLINES 5000 /*max #lines to be sorted */

char *lineptr[MAXLINES]; /*pointers to read the lines  */
int readlines(char *lineptr[],int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left , int right);

/*sort input lines*/
int main(){
  int nlines;
  /*apply algorithm */
  if((nlines=readlines(lineptr,MAXLINES))>=0){
    qsort(lineptr,0,nlines-1);
    writelines(lineptr,nlines);
    return 0;
  }
  else{
    printf("error : Input too big to sort");
    return 1;
  }
}

#define MAXLEN 1000 /*maximum length of input array */

int getline(char *,int);
char *alloc(int);

/*readlines : read input lines */
int readlines(char *lineptr[],int maxlines){
  int len,nlines=0;
  char line[MAXLEN],*p;
  while((len=getline(line,MAXLEN))>0)
    if(nlines>=maxlines || (p = alloc(len)) == NULL)
      return -1;
    else{
      line[len-1] = '\0'; /* delete newline */
      strcpy(p,line);
      lineptr[nlines++] = p;
    }
  return nlines;
}


/*writelines : write output lines */
void writelines(char* linesptr[],int nlines){
  while(nlines-->0)
    printf("%s\n",(*lineptr)++);
}


void qsort(char *v[],int left , int right){
  int i ,last;
  void swap(char *v[],int i, int j);
  if(left>=right) /*if there are no or only one element */
    return;
  swap(v,left,(left+right)/2);
  last = left ;
  for(i=left+1;i<=right;++i)
    if(strcmp(v[i],v[left])<0)
      swap(v,++last,i);
  swap(v,left,last); /*inserting pivot at its proper place */
  qsort(v,left,last-1);
  qsort(v,last+1,right);
}

/*swap : swap the 2 elements */
void swap(char*v[],int i, int j){
  char *temp;
  temp = v[i];
  v[i]=v[j];
  v[j] = temp;
}

#define ALLOCSIZE 10000 /* size of availaible space */

static char allocbuf[ALLOCSIZE]; /*storage for alloc */
static char *allocp = allocbuf ; /*next free position in buffer*/
char *alloc(int n){
  if(allocbuf + ALLOCSIZE - allocp >= n){ /* it fits */
    allocp+=n;
    return allocp - n; /* old allocp */
  }
  else {
    return 0;
  }
}
