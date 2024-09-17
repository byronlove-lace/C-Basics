#include <stdio.h>
#include <z.h>

int xfn(void);

int main(int argc, char *argv[])
{
        printf("%d\n", xfn());
}

int xfn(void)
{
        return yfn(1);
}
