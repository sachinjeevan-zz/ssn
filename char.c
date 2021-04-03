#include<stdio.h>
#include<limits.h>
int main() 
{
    int a = INT_MIN; // 4 bytes = 32 bit // 2^32 = 4294967296/2 = 2147483648
    int b = INT_MAX;
    printf("%d %d",a,b);
}
