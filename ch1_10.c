#include<stdio.h>
main(){
int ch;
while((ch=getchar())!=EOF){
if(ch=='\t')printf("\\%c",'t');else if(ch == '\b') putchar('\b');
else if(ch == '\\')printf("\\\\");else printf("%c",ch);
}
}
