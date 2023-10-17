#include <stdio.h>
int main() {
    float far;
    float cels;
    printf("Please enter a temperature in farenheit: ");
    scanf("%f", &far);
    cels = (far - 32)/1.8;
    printf("The temperature is %f degrees in celsius\n", cels);
    return 0;
}