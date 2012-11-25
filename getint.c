#include<ctype.h>
#include<stdio.h>

#define BUFSIZE 100
char buf[BUFSIZE];
int getch(void);
void ungetch(int);
int bufp=0;

/* getint(): get next integer from input into *pn */
int getint(int *pn){
  int c,sign;
  while(isspace(c=getch())); /* skip white spaces */
  if(!isdigit(c) && c!=EOF && c!='+' && c!='-'){
    ungetch(c);
    return 0;
  }
  sign = (c=='-')?-1:1;
  if(c=='-' || c=='+')
    c = getch();  /*get next character if previous one was a + or -*/
  if(c <'0' || c >'9'){/*if anything followed by + or - is not a no. then it should be returned back to the buffer so that default value taken should not                          be  a zero*/
    ungetch(c);
    //printf("printing the ungetched character: %c ",getch());
    return 0;
  } 
  for(*pn = 0 ; isdigit(c); c = getch())
    *pn = 10 * *pn + (c-'0');
  *pn *= sign;
  if(c!=EOF)
    ungetch(c);
  return c;
}
//------------------------------------------------------------
int getch(void){  /* get a (possibly pushed back) character */
  return (bufp > 0) ? buf[--bufp] : getchar();
}

//------------------------------------------------------------
void ungetch(int c){  /* push character back on input */
  if(bufp >=BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}
//-----------------------------------
void print(int *pn){
  int i;
  for(i=0;i<5;++i){
    printf("%d ",*pn);
    pn++;
  }
}
// -------The main function --------
int main(){
  int array[100],n;
  //print(array);printf("\n");
  //array[0] = 4;
  //print(array);printf("\n");
  for(n=0;n<5 && getint(&array[n]) != EOF;++n)/*numbers to be accumulated inside array buffer */
    ;
  print(array);
  return 0;
}
