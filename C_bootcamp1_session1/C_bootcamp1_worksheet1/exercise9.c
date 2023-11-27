#include <stdio.h>
int main() {
    int days;
    long long int distance;
    printf("Enter a number of days: ");
    scanf("%d", &days);

    distance = days * 299792.458 * 60 * 60 * 24;

    printf("Light will travel %lldkm in %d days\n", distance, days);
    return 0;
}