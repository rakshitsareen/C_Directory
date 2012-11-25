#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

void reverse(char s[]){
  int temp ;
  int i=0,j=strlen(s)-1;
  while(s[i] && i<j){
    temp = s[i];
    s[i]=s[j];
    s[j]=temp;
    i++;
    j--;
  }
}
void itoa(int n , char s[]){
  int i,sign=0;
  //printf("%d\n\n",n);
  if((sign=n)<0) n = -n;
  //printf("%d\n\n",n);
  i=0;
  do{
    printf("%d\n",n);
    s[i++]= abs(n%10) + '0';
  }while(abs(n/=10)>0);
  if(sign <0) s[i++]='-';
  s[i]='\0';
}
main(){
  printf("%d\n",sizeof(int)*8);
  int x =(int)-pow(2,(sizeof(int)*8)-1),i;
  char s[12];
  for(i=0;i<12;++i) s[i] = 0;
  itoa(x,s);
  reverse(s);
  printf("%s",s);
}
