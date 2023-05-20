#include <stdio.h>

int main()
{
    float w, h, BMI;
    scanf("%f\n%f", &w, &h);
    BMI = w / ((h / 100) * (h / 100));
    printf("%.1f", BMI);
}