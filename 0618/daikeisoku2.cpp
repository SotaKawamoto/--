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
    int n,k;
    double h, s;

    //������������
    n = 100;
    h = (b - a) / n;
    s = (f(a) + f(b)) * h / 2;
    for (k = 0; k < n; k++) {
        s += f(a + k * h) * h;
    }
    return(s);
}
double f(double x)
{
    return(x * x);
}
