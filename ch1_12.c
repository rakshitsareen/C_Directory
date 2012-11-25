#include<stdio.h>
main(){
int ch;
while((ch=getchar())!=EOF){
if(ch == ' '||ch == '\t')printf("\n");else printf("%c",ch);
}
}
