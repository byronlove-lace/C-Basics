#include <stdio.h>

int main()
{
        int x = 1;

        int *pX = &x;
        int &rX = x;

        *pX += 1;
        rX += 1;

        printf("%d\n", x);
        
        return 0;
}
