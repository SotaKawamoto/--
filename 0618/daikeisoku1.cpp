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

    //�����̂܂�
    n=100;
    h = (b - a) / n;
    s = 0;
    for (k = 0; k < n; k++) {
        s += (f(a + k * h) + f(a + (k + 1) * h)) * h / 2.0;
        //台形のsum
    }
    return(s);
}

double f(double x)
{
    return(x * x);
}
