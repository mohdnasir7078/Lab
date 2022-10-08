#include <stdio.h>
#include <math.h>
#define f(x) (x * x * x) - (x * x) + 2
int main()
{
    double a, b, c, pre;
    double fa, fb, fc;
    int i = 0;
    printf("A and B -> ");
    scanf("%lf %lf", &a, &b);
    do
    {
        fa = f(a);
        fb = f(b);
        c = (a + b) / 2.0;
        fc = f(c);
        pre = fc;

        if (fc < 0)
        {
            if (fa < 0)
                a = c;
            else
                b = c;
        }
        else if (fc > 0)
        {
            if (fa > 0)
                b = c;
            else
                a = c;
        }

        i++;
        printf("Iterations = %d || Root = %.3lf || Value = %lf\n", i, c, fc);
        c = (a + b) / 2.0;
        fc = f(c);
    } while ((fabs(fc) - (pre)) > 0.00001);
    return 0;
}