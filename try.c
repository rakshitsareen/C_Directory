#include<stdio.h>
char *getString()
{
    char str[20] = "Will I be printed?\n";
    printf("%s",str);
    return str;
}
void hello()
{
    int p=9;
}
int main()
{
    char *s = getString();
    hello();
    printf("%s", s);
    getchar();
    return 0;
}
