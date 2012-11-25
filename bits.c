#include<stdio.h>
int getbits(unsigned int);
int main(){
unsigned int j;
int i = 0;
for(j=1;j<=17;j++)
i += getbits(j);
printf("%d",i);
return 0;
}

int getbits(unsigned int t){
int count = 0;
while(t){
if(t & 1)
count++;
t=t>>1;
}
return count;
}
