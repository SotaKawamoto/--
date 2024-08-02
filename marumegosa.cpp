/* 丸め誤差 */
//同程度の値の減算で丸め誤差が生じたりする
#include <stdio.h>
#include <math.h>

int main(void)
{

//変数定義
    FILE* fp;
    int i, j, k;
//    float a, b, c;
    double a, b, c;
//    float ans;
    double ans;
    
    // Open the file for writing
    if (fopen_s(&fp, "marumegosa.txt", "w") != 0) {
        printf("Error opening the file.\n");
        return 1;
    }


//有効数字の確認

    a = 1000000.0;
    b = 1.0;
    ans = a + b;
    printf("ans 100万+ 1 =%16.14f\n", ans);
    // Write the result to the file
    fprintf(fp, "ans= 100万+ 1 =%16.14lf\n", ans);
    //全体の桁数より小数点以下の桁数優先

    a = 1000000.0;
    b = 0.1;
    ans = a + b;
    printf("ans 100万 + 0.1 =%16.14f\n", ans);
    fprintf(fp, "ans= 100万+ 1 =%16.14lf\n", ans);

    a = 1000000.0;
    b = 0.01;
    ans = a + b;
    printf("ans 100万 + 0.01 =%16.14f\n", ans);
    fprintf(fp, "ans= 100万+ 1 =%16.14lf\n", ans);

    // Close the file
    fclose(fp);
}