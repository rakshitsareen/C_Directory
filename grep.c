#include<stdio.h>
#define MAXLINE 1000

int equal(char s[], char t[], int a);
int getlin(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";
/* find all the lines matching pattern */
main(){
  char line[MAXLINE];
  int found = 0;

  while(getlin(line,MAXLINE) > 0)
    if(strindex(line,pattern) >= 0) {
      printf("%s",line);
      found++;
    }
  return found;
}

/* getlin : get line into s , return length */
int getlin(char s[],int lim){
  int c,i=0;
  while(--lim > 0 && (c=getchar())!=EOF && c!='\n')
    s[i++] = c;
  if(c == '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[],char t[]){
  printf("Inside strindex\n");
  int i,j,k,save_i = -1;

  for(i = 0; s[i] != '\0'; i++){
    if(equal(s,t,i)){
      save_i = i,printf("%d ",save_i);
    }
  }
  return save_i;
}

int equal(char s[], char t[] ,int i){
  int a=0,j=i;
  while(t[a] && s[j]){
    if(t[a]!=s[j]){
      printf("Returning -1\n");
      return -1;
    }
    else if(t[a]==s[j]){
      a++;
      j++;
    }
  }
  printf("Returning 1\n");
  return 1;
}
