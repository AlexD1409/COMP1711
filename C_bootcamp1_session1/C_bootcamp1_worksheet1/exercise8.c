#include <stdio.h>
int main() {

    int input;
    float fact = 1;
    int a = 1;

    printf("Enter a number to get the factorial: ");
    scanf("%d", &input);

    while(a<=input)
    {
        fact *= a;
        a++;
    }


    printf("The factorial is %f\n", fact);
    return 0;
}