#include <stdio.h>

int main()
{
    for (int c=334; c<1000; ++c)
    {
        for (int b=(1000-c)/2+1; b<c; ++b)
        {
            int a = 1000 - b - c;
            if (a * a + b * b == c * c)
            {
                printf("%d\n", a * b * c);
                return 0;
            }
        }
    }
    return 0;
}
