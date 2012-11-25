/* getfloat.c : retrieving floating point no.s from stream and saving them to an array */
#include<stdio.h>
#include<ctype.h>
#include<math.h>
#define BUFSIZE 100
#define SIZE 10

float buffer[SIZE];
int bufp = 0;
float getch(void);
void ungetch(float);
float getfloat(float *);
void print(float *);
int main(){
  float array[SIZE];int n;
  for(n=0;n<1 && getfloat(&array[n])!=EOF;++n)
    ;
  print(array);
  return 0;
}

float getfloat(float *s){
  float c,dp;
  int sign,i=0;
  while(isspace(c=getch()));/* skip white spaces */
  if(!isdigit(c) && c !=EOF && c!='+' && c!= '-'){printf("i am returning\n");
    ungetch(c);
    return 0.0;
  }printf("here am i\n ");
  sign = (c=='-')?-1:1;
  if(sign == '-' || sign == '+'){printf("there is a sign\n");
    c = getch();}
  if(!isdigit(c) && c != '.'){ /* if anything that follows + or - is anything else other that a . [dot] , then it should be ignored and returned to the buffer and 0.0 should be returned */
    ungetch(c);
    return 0.0;
  }
  for(*s=0;isdigit(c);c = getch()) /* get the main part */
    *s = 10 * *s + (c-'0');
  //dp = s;
  if(c == '.'){
    c = getch(); /* get the decimal part */
    for(dp = 0;isdigit(c);c = getch()){
      dp = 10 * dp + (c-'0');
      i++;
    }
    dp/=pow(10,i); /*convert into decimal */
    *s += dp; /* add this decimal part to the *s (non decimal part) */
    *s*=sign;
  }
  return *s; /* return number*/
}
//--------------------
float getch(void){/* get a possibly pushed back character */
  return (bufp > 0)?buffer[--bufp] : getchar();
}
//--------------------
void ungetch(float c){
  if(bufp > BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buffer[bufp++] = c;
}
//---- print the array -------
void print(float *s){
  int i;
  for(i=0;i<1;++i){
    printf("%f ",*s);
    s++;
  }
}
//---- end of program ------
