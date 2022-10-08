#include <stdio.h>
#include <math.h>
int main()
{
    printf("                GAUSS ELIMINATION METHOD.\n");
    int size, k, vn;
    printf("Please Enter No of Variable :");
    scanf("%d", &size);
    printf("                Input %d * %d Matrix.\n", size, size + 1);
    float m[size][size + 1];
    float div, mul, sum = 0;
    for (int i = 0; i < size; i++)
        for (int j = 0; j <= size; j++)
            scanf("%f", &m[i][j]);

    printf("\n          Equation is.\n");
    for (int i = 0; i < size; i++)
    {
        vn = 123 - size;
        for (int j = 0; j <= size; j++)
        {
            if (j == 0 && m[i][j] < 0)
                printf("-");
            if (j != 0 && j < size)
            {
                if (m[i][j] >= 0)
                    printf(" + ");
                else
                    printf(" - ");
            }
            if (j < size)
                printf("%0.1f%c", fabs(m[i][j]), vn);
            if (j == size - 1)
                printf(" = %0.1f", m[i][j + 1]);
            vn++;
        }
        printf("\n");
    }

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            div = m[j][i] / m[i][i];
            for (int k = 0; k <= size; k++)
                m[j][k] = m[j][k] - (div * m[i][k]);
        }
    }
    float ans[size];

    for (int i = size - 1; i >= 0; i--)
    {
        sum = 0;
        for (int k = 0; k < size; k++)
            if (k != i)
                sum += m[i][k];
        m[i][size] -= sum;
        mul = m[i][size] / m[i][i];
        m[i][size] = mul;
        ans[i] = mul;
        for (int j = i - 1; j >= 0; j--)
            m[j][i] *= mul;
    }

    vn = 123 - size;
    printf("\n          Solution is.\n");
    for (int i = 0; i < size; i++)
    {
        printf("%c = %0.2f\n", vn, ans[i]);
        vn++;
    }
    return 0;
}