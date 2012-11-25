#include<stdio.h>
#include<stdlib.h>
void print(char *);
int int main(int argc, char const *argv[])
{
	int array[11],i;
	for (int i = 0; i < 11; ++i)
	{
		array[i] = rand()%11;
	}
	return 0;
}

void print(char *s){
	int i;
	for (int i = 0; i < 11; ++i)
	{
		printf("%d\n", *s);
		s++;
	}
}