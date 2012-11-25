#include<stdio.h>
main(){
  int ch,ar[26],i,j;
  for(i=0;i<26;++i)ar[i]=0;
  while((ch=getchar())!=EOF){
    if(ch>=65 && ch<=91)
      ++ar[ch-'A'];
    else if(ch>=97 && ch<=122)
      ++ar[ch-'a'];
  }
  for(i=0;i<26;++i){
    printf("\n\n%c--|",i+97);
    for(j=0;j<ar[i];++j)
      printf("#");
  }
  printf("\n");
}
