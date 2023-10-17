#include <stdio.h>
int main() {
    int input;
    printf("Please enter a number: ");
    scanf("%d", &input);
    if (input % 2 == 0) {
         printf("The number is even\n");
    }else printf("The number is odd\n");
return 0;
    
}