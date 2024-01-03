#include <stdio.h>

int main(){
    float value;
    float vat;
    float total;
    int tax;
    float hundredth;

    printf("Please enter vat percentage\n");
    scanf("%d", &tax);

    printf("Please enter the TOTAL value\n");
    scanf("%f", &total);

    hundredth = total/(100 + tax);
    vat = hundredth * tax;
    value = hundredth * 100;
    printf("The VAT is %.2f\nThe original value with NO VAT is %.2f\n", vat, value);
    
    return 0;
    }

    