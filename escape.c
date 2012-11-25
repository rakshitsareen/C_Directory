#include<stdio.h>
void escape(char t[],char s[]){
  int i=0,k=0;
  while(s[i]!='\0'){
    if((s[i]!='\t')&&(s[i]!='\n')){t[k++]=s[i];i++;}
    else{
      switch(s[i]){
      case '\t': t[k++]='\\';t[k++]='t';i++;break;
      case '\n': t[k++]='\\';t[k++]='n';i++;break;
      }
    }
  }
  t[k]='\0';     // never forget the null character ;
}
main(){
  char c='0',s[100],t[298];
  int i=0;
  while(i<100 && c!=EOF){
    c=getchar();
    s[i]=c;i++;
  }
  s[--i]='\0';  // never forget the null character ;
  escape(t,s);
  printf("%s",t);
}
