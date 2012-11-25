/* Question asked at microsoft */

#include<stdio.h>
#include<math.h>

char cellCompute(char cells , int days){
int ans=0;;
int a[8];
int i = 0,temp=0 ;
int d=1,right = 0;
//printf("%d",(cells>>1)&0x01);
for(i=0;i<8;i++){
a[i] = (cells>>(7-i)&0x01);
printf("%d",a[i]);
}
printf("\n");
for(d=1;d<=days;d++){temp = 0;
	for(i=0;i<7;i++){
		if(temp^a[i+1] == 0){
			temp = a[i];
			a[i] = 1;
		}
		else{
			temp = a[i];
			a[i] = 0;
		}
	}
	if(temp^right == 0){
		a[7] = 1;
	}
	else {
		a[7] = 0;
	}
}
for(i = 0; i < 8 ; i++){
printf("%d",a[i]);
}
for(i=0;i<8;i++){
//ans = 0;
ans = ans + a[i]*pow(2,7-i);
}
printf("\n%d\n",ans);
return (char)ans;
}

int main(){
char input;
char res;
scanf("%d",&input);
res = cellCompute(input,3);
//printf(" = %c\n",res);
return 0;
}
