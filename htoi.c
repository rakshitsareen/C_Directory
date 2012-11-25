#include<stdio.h>
#include<math.h>
#define MAX 6
int htoi(char []);
int to_int(char []);
main(){
  char s[MAX];
  int hex;
  printf("Enter string in hexadecimal form :");
  scanf("%s",s);
  hex = htoi(s);
  printf("The no. in integer form is : %d\n",hex);
  return 0;
}

/* implementation of htoi(s) function */

int htoi(char s[]){
  int automatic_hex_to_int=1;
  int i = 0;
  char __s_automatic[MAX];
 if(s[0]=='0' && (s[1]=='x'||s[1]=='X')) i+=2;
 else { printf("Wrong type of input. Please Enter again : ");
   scanf("%s",__s_automatic);
   htoi(__s_automatic);
    }
 while(s[i]!='\0'){
   if(to_int(s[i])>='0' && to_int(s[i])<=to_int('F')){
     automatic_hex_to_int = to_int(s[i])*pow(16,i) + automatic_hex_to_int;++i;
   }
 }
 return automatic_hex_to_int;
}

/* impementation of to_int */
int to_int(char s[]){
  int temp;
  switch(s){
  case '0' : temp =  0;break;
  case '1' : temp =  1;break;
  case '2' : temp =  2;break;
  case '3' : temp =  3;break;
  case '4' : temp =  4;break;
  case '5' : temp =  5;break;
  case '6' : temp =  6;break;
  case '7' : temp =  7;break;
  case '8' : temp =  8;break;
  case '9' : temp =  9;break;
  case 'A' : temp = 10;break;
  case 'B' : temp = 11;break;
  case 'C' : temp = 12;break;
  case 'D' : temp = 13;break;
  case 'E' : temp = 14;break;
  case 'F' : temp = 15;break;
  default  :printf("Unindentified hexadecimal parse error\n");
  }
  return temp;
}
