#include <stdio.h>

int main()
{
    int S0, S1_alpha, S1_ultimate;
    int ELEMENTS = 3;
    int Add_element[3], Remove_element[3];
    int Intersection, Union;
    scanf("%d\n%d", &S0, &S1_alpha);
    scanf("%d %d %d", &Add_element[0], &Add_element[1], &Add_element[2]);
    scanf("%d %d %d", &Remove_element[0], &Remove_element[1], &Remove_element[2]);
    S1_ultimate = S1_alpha;
    for (int element = 0; element < ELEMENTS; element++)
    {
        S1_ultimate |= (1 << Add_element[element]);
    }
    for (int element = 0; element < ELEMENTS; element++)
    {
        S1_ultimate &= ~(1 << Remove_element[element]);
    }
    Intersection = S1_alpha & S1_ultimate;
    Union = S1_alpha | S1_ultimate;
    if ((S0 & S1_ultimate) == S1_ultimate)
    {
        printf("Y\n");
    }
    else
    {
        printf("N\n");
    }
    printf("%d\n", Intersection);
    printf("%d", Union);
    return 0;
}
