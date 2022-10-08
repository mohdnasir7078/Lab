#include <stdio.h>
#include <math.h>
double Value(double x)
{
    return x * x - 2 * x - 1;
}
double diff(double x)
{
    return 2 * x - 2;
}
int main()
{
    double a, b;
    printf("Pease Enter Range :");
    scanf("%lf%lf", &a, &b);
    double f_a = Value(a);
    double f_b = Value(b);
    double x0, x1, temp;
    int i = 0;
    if (fabs(f_a) < fabs(f_b))
        x0 = a;
    else
        x0 = b;
    do
    {
        x1 = x0 - ((Value(x0)) / diff(x0));
        x0 = x1;
        i++;
        temp = x0 - ((Value(x0)) / diff(x0));
        printf("Iterations = %d || Root = %.5lf\n", i, x1);
    } while (fabs(temp - x1) > 0.00001);
    return 0;
}