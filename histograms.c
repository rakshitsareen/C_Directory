#include<stdio.h>
main(){
int c,j,i=0,ar[100],flag=0;
for(i=0;i<100;++i) ar[i] = 0;	// never forget to initialize the array with initial values or it will take garbage ;
i=0;
while((c=getchar())!=EOF){
if((c == ' '||c == '\n' || c == '\t')&&flag == 1) // flag == 1 means inside a word;
{++i;flag = 0;	//now i am ouside a word ;
}
else if(c!=' ' && c!= '\n' && c!= '\t') {++ar[i];flag =1;}	// inside again ; 
}
for(flag = 0 ;flag<i;++flag){
for(j=0;j<ar[flag];++j)
  printf("#");
printf("\n");
}
}
