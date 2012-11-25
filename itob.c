#include<stdio.h>
#include<string.h>

void reverse(char s[]);
void itob(int , char[],int);
int main(){
  int no,base,i;
  char s[12];
  for(i=0;i<12;++i) s[i] = '0';
  scanf("%d",&no);
  scanf("%d",&base);
  if(base == 1){
    printf("Invalid base"); exit(1);
  }
  itob(no,s,base);
  printf("Returned from itob \n");
  printf("%s",s);
  return 0;
}

void itob(int n,char s[], int b){
  int i=0;
  char temp;
  printf("Entered itob\n");
  while(n>0){
    printf("In itob's while\n");
    temp = n % b + '0';
    switch(temp){
    case 10+'0':s[i++] = 'A';break;
    case 11+'0':s[i++] = 'B';break;
    case 12+'0':s[i++] = 'C';break;
    case 13+'0':s[i++] = 'D';break;
    case 14+'0':s[i++] = 'E';break;
    case 15+'0':s[i++] = 'F';break;
    default:s[i++] = temp;
    }
    n = n / b;
  } // while ends
  s[i]='\0';
  reverse(s);
}


void reverse(char s[]){
  int temp ;
  int i=0,j=strlen(s)-1;
  printf("j is : %d\n",j);
  while(s[i] && i<j){
    printf("In reverse \n");
    temp = s[i];
    s[i]=s[j];
    s[j]=temp;
    i++;
    j--;
  }
}
