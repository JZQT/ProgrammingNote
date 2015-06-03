#include <stdio.h>

int main()
{
    int squareofsum = 0;
    int sumofsquare = 0;
    for (int i=1; i<=100; ++i)
    {
        squareofsum += i;
        sumofsquare += i * i;
    }
    squareofsum *= squareofsum;
    printf("%d\n", squareofsum - sumofsquare);
    return 0;
}
