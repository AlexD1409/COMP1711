#include <stdio.h>

float SphereVolume (float radius)
{
    float volume;
    volume = (4.0/3.0) * 3.1459 * radius * radius * radius;
    return volume;
}

int main()
{
    float radius;
    printf("Enter a radius to find the volume: ");
    scanf("%f", &radius);
    printf("The volume is %f\n", SphereVolume(radius));
    return 0;
}