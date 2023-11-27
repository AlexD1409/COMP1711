#include <stdio.h>
int main() {
    int a, b, c;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    c = a;
    a = b;
    b = c;
    printf("The first number was %d, the second number was %d\n", a, b);
    return 0;
}