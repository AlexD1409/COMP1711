#include <stdio.h>
int main() {

    int a;
    printf("Input a number: ");
    scanf("%d", &a);

    if (a==0)
    {
        printf("The number is 0\n");
    } 
    else if (a<0)
    {
        printf("The number is less than 0\n");
    }
    else
    {
        printf("The number is greater than 0\n");
    }

    return 0;
}