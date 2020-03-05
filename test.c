#include "string.h"
#include "stdio.h"

int main()
{
    typedef struct test
    {
        char *a;
    } Test ;
    Test *c,d;
    c=&d;
    c->a="Sad so sad";
    printf("%s",c->a);
    return 0;
}
