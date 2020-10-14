#include<stdio.h>
int add(int,int);

int add(int a,int b)
{
    return a+b;
}

int main(int argc, char const *argv[])
{
    printf("Welcome to Your 1st Program Kamal\n");
    printf("Addition = %d\n",add(30,40));
    return 0;
}
