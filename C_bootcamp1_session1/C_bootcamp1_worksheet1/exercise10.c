#include <stdio.h>
int main() {
    float rate, value, initial, percentage;
    int years, a;

    printf("What is the starting amount?\n");
    scanf("%f", &value);

    printf("What is the yearly interest rate? (e.g. 5%%)\n");
    scanf("%f", &percentage);

    printf("How many years will the interest apply for?\n");
    scanf("%d", &years);

    initial = value;
    rate = 1 + (percentage/100);

    for (a=0; a<years; a++)
    {
        value *= rate;
    }

    printf("The total value with interest will be %f, the amount of interest gained will be %f\n", value, value - initial);

    return 0;
}