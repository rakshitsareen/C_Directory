/* hard logic */

#include<stdio.h>

unsigned setbits(unsigned x, int p,int n,unsigned y){
  int a,b;
  a=b=0;
  a=(((x>>(p+1-n)) & (~0<<n)) | (~(~0<<n) & y)) << (p+1-n);
  b=(a^x)&(~(~0<<(p+1-n)));
  b=(~b& (~(~0<<(p+1-n))));
  return a|b;
}

main(){
  printf("%d",setbits(15,3,4,16));
}
/* OUTPUT 
 * 0
 */
