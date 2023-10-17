#include <stdio.h>
int main () {
    int a , b;
    
    printf("Please enter two numbers to add: ");
    scanf("%d %d", &a , &b);
    printf("The answer is %d", a + b);
    return 0;
}