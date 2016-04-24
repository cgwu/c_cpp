
#include <stdio.h>
#include <stdarg.h>

int sum(int num, ...)
{
    int total = 0;
    va_list argptr;
    va_start(argptr,num);
    for (; num > 0; num--) {
        total += va_arg(argptr, int);
    }
    va_end(argptr);
    return total;
}

void my_printf(char *format, ...)
{
    va_list ap;
    va_start(ap, format);
    for(; *format; ++format)
    {
        if(*format == 's')
        {
            printf("print string:%s\n", va_arg(ap, char*));
        }
        else if(*format == 'd')
        {
            printf("print int:%d\n", va_arg(ap, int));
        }
        else if(*format == 'f')
        {
            printf("print float:%f\n", va_arg(ap, double));
        }
        else if(*format == 'c')
        {
            printf("print char:%c\n", (char)va_arg(ap, int));
        }

    }
    va_end(ap);
}

int main()
{
    int s1 = sum(4,1,2,3,4);
    printf("s1=%d\n",s1);

    int s2 = sum(5,1,2,3,4,-5);
    printf("s2=%d\n",s2);

    my_printf("sdfc", "Hello中国", 12345, 3.1415926d, 'Y');

    my_printf("ssddffcc", "Hello","World", 888, 12345, 5.123,  3.1415926d, 'Y','G');

    return 0;
}
