/* ��`���ɂ�鐔�l�ϕ��̏������֐��Ƃ��� */
#include <stdio.h>
#include <math.h>

/* ��`���̏��������s����֐� */
double daikei(double, double, double);
double f(double);

int main()
{
    double a = 0.0, b = 1.0;
    double eps = 1.0e-5;
    printf("%.10lf\n", daikei(a, b, eps));
}

double daikei(double a, double b, double eps)
{
    int n = 1;
    int k;
    double h = (b - a) / n;
    double s0;
    double s;
    double err = 1.0;

    //�������������t��
    s0 = (f(a) + f(b)) * h / 2;
    while (err > eps) {
        n = n * 2;
        h = h / 2;
        s = s0 / 2;
        for (k = 1; k < n; k += 2) {
            s += f(a + k * h) * h;
        }
        err = fabs(s - s0);
        s0 = s;
        printf("Err=%f\n", err);
    }
    return(s);
}


double f(double x)
{
    return(x * x);
}