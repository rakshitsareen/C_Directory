#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

#define MAXOP 100
#define BUFSIZE 100
#define NUMBER '0'
#define MAXVAL 100

//DECLARATIONS

int sp = 0;         /* next free stack position */
double val[MAXVAL];
char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;       /* next free position in buffer */
int op = 0;         /* initially no operation performed */
int flag = 0;       /* initially fxn not called */  

int getch(void);
void ungetch(int);
int getop(char []);
void push(double);
double pop(void);
void print_top_of_stack();
void clear_stack();              /* clear stack at any point of time */
void print_stack();
//------------------------------------------------

/* reverse Polish calculator */
int main(){
  int type;
  double op2;
  char s[MAXOP];

  while((type = getop(s)) != EOF){
    switch(type){
    case NUMBER:
      //printf("pushing %g\n",atof(s));
      push(atof(s));
      //printf("%g is pushed\n",atof(s));
      break;
    case 's':
      flag = 1;
      push(sin(pop()));
    case '@':
      //printf("inside @ case\n");
      print_top_of_stack();
      break;
    case '~':
      clear_stack();	/* to clear the stack */
      break;
    case '+':
      //printf("+ case\n");
      push(pop()+pop());
      op = 1;
      break;
    case '-':
      //printf("- case\n");
      op2 = pop();
      push(pop()-op2);
      op = 1;
      break;
    case '/':
      //printf("/ case\n");
      op2 = pop();
      if(op2!=0){
	push(pop()/op2);
	op = 1;
      }
      else
	printf("error: zero divison\n");
      break;
    case '*':
      //printf("* case\n");
      push(pop()*pop());
      op = 1;
      break;
    case '\n':
      // printf("new line case\n");
      if(flag){
	flag = 0;
	break;
      }
      printf("\t%.8g\n",pop());
      break;
    case '#':
      print_stack();
      break;
    case '%':
      op2 =pop();
      if(op2!=0.0)
	push(fmod(pop(),op2));
      break;
    default:
      //printf("default case");
      printf("error: unknown command %s\n",s);
      break;
    }
  }
  return 0;
}
//----------------------------------------------------------------------

/* push: push f onto stack */
void push(double f){
  if(sp<MAXVAL){
    //printf("pushing inside push fxn %g\n",f);
    val[sp++] = f;
    //printf("stack pointer at %d\n",sp);
  }
  else 
    printf("error: stack full, can't push %g\n",f);
}
 
double pop(void){
  //printf("pop called\n");
  if(sp>0)
    return val[--sp];
  else{
    printf("error: stack empty\n");
    //printf("sp = %d \n",sp);
    return 0.0;
  }
}

//------------------------------------------------------------------
/* getop: get next operator or numeric operand */
int getop(char s[]){
  int i,c;
  while((s[0] = c = getch()) == ' ' || c == '\t') /* skip till blank spaces */
    ;
  if(s[0]=='~'){
    flag = 1;
    return '~';
  }
  if(s[0]=='@'){
    flag = 1;
    return '@';
  }
  if(s[0]=='#'){
    flag = 1;
    return '#';
  }
  if(s[0] == '!'){
    flag = 1;
    return '!';
  }
  s[1] = '\0';
  i=0;
  if(s[0]=='s'){
    if((s[1]=getch())=='i'){
      if((s[2]=getch())=='n'){
	flag = 1;
	return 's';
      }
      else
	printf("Unknown symbol\n");
    }
  }
  if(c == '-'){
    if(isdigit(c = getch()) || c == '.')
      s[++i] = c; /* store negative sign in array */
    else{
      if(c!=EOF){
	ungetch(c);
	c = '-';
	//return '-';
      }
    }
  }
if(!isdigit(c) && c != '.')
    return c;   /* not a number */
  if(isdigit(c)) /* collect integer part */
    while(isdigit(s[++i] = c = getch()))
      ;
  if(c == '.')
    while(isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  if(c != EOF)
    ungetch(c);
  return NUMBER;
}
//---------------------------------------------------------------------------
int getch(void){  /* get a (possibly pushed back) character */
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){  /* push character back on input */
  if(bufp >=BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}

void print_top_of_stack(){
  if(sp>0){
    printf("%g\n",val[sp-1]);
    return;
  }
  if(sp == 0){
    if(op){
      printf("%g\n",val[sp]);
      return;
    }
    else{
      printf("Empty stack\n");
      return;
    }
  }
  //   else if(sp>0){
  //    printf("%g\n",val[sp-1]);
  //  }
}
//-----------------------------------------------------
//clear stack
void clear_stack(){
  int i = 0 ;
  for(i=0;i<MAXVAL;++i){
    val[i] = 0.0;
  }
  printf("\n\nStack Cleared \n\n");
}
//---------------------------------------------------
//print stack
void print_stack(){
  int i;
  for(i=0;i<sp;++i){            /* print till present position of stack pointer */
    printf("%d : %g \n",i,val[i]);
  }
  printf("So this is the stack\n");
}
