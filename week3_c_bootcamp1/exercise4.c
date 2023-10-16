#include <stdio.h>
int main() {
    int temp;
    printf("Please enter a temperature: ");
    scanf("%d", &temp);
    
    if (temp >= -10 && temp <= 40)
    {
        printf("The temperature is within range\n");
    }
    else 
    {
        printf("The temperature is not within range\n");
    }

    return 0;
}