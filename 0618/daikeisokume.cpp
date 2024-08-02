#include <stdio.h>
#include <math.h>


double daikei(double, double, double);//台形則の定義
double f(double);//関数のアレンジだからここを変えればよい

int main()
{
    double a = 0.0, b = 1.0;//積分区間　定義域の定義
    double eps = 1.0e-5;//誤差 epsilonの定義
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

    s0 = (f(a) + f(b)) * h / 2;
    while (err > eps) {//収束判定

    //台形則の式を整理して高速化
    //ループ内の処理が少ない
        n = n * 2;
        h = h / 2;
        s = s0 / 2;
        for (k = 1; k < n; k += 2) {
            s += f(a + k * h) * h;
        }
        err = fabs(s - s0);
        s0 = s;
        printf("Err=%f\n", err);//誤差の表示 収束判定
    }
    return(s);
}


double f(double x)//課題はサイクロイドの計算でもしようかな
{
    
    return();
}