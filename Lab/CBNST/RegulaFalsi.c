#include <stdio.h>
#include <math.h>
double ValueCal(double x)
{
    return x * x * x - (2 * x) - 5;
}
int main()
{
    double x0, x1, temp, temp1;
    int i = 0;
    printf("Please Enter Root Range :");
    scanf("%lf %lf", &x0, &x1);
    if (x0 > x1)
    {
        double temp = x0;
        x1 = x0;
        x0 = temp;
    }
    do
    {
        temp = x0 - (((x1 - x0) / (ValueCal(x1) - ValueCal(x0))) * ValueCal(x0));
        if (ValueCal(temp) < 0)
            x0 = temp;
        else
            x1 = temp;
        temp1 = x0 - (((x1 - x0) / (ValueCal(x1) - ValueCal(x0))) * ValueCal(x0));
        i++;
        printf("Iterations = %d || Root = %.5lf || Value = %lf\n", i, temp, ValueCal(temp));
    } while ((fabs(temp1) - (temp)) > 0.00001);

    return 0;
}