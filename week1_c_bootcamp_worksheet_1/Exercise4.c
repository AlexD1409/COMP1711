#include <stdio.h>
int main() {
    float radius, area;
    printf("Enter the radius of the cirlce: ");
    scanf("%f", &radius);
    area = radius * radius * 3.141592653;
    printf("The area of the circle is %f\n", area);
    return 0;
}