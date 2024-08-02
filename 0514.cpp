#include <stdio.h>
#include <math.h>

#define MAX 

void inverse(double matrix[MAX][MAX], double inverseMatrix[MAX][MAX], int n);
void calculateCofactor(double matrix[MAX][MAX], double cofactorMatrix[MAX][MAX], int n);
double calculateDeterminant(double matrix[MAX][MAX], int n);

int main() {
    int n;
    printf("n×n行列式のnの代入(n>5): ");
    scanf_s("%d", &n);

    if (n <= 5) {
        printf("n must be greater than 5.\n");
        return 1;
    }

    double matrix[MAX][MAX] = { 0 };
    double inverseMatrix[MAX][MAX] = { 0 };

    printf("行列の成分の代入（行にそって）:\r\n");
    // matrix読み込み
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf_s("%lf", &matrix[i][j]);
        }
    }

    // n×n matrixからdeterminantを計算
    double determinant = calculateDeterminant(matrix, n);

    // 正則判定
    if (determinant == 0) {
        printf("逆行列は存在しない\r\n");
        return 1;
    }

    // 逆行列を計算
    inverse(matrix, inverseMatrix, n);

    // 逆行列を表示
    printf("求める逆行列:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inverseMatrix[i][j] /= determinant;  // 逆行列を計算
            printf("%lf ", inverseMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

double calculateDeterminant(double matrix[MAX][MAX], int n) {
    double det = 0.0;
    if (n == 1) {
        return matrix[0][0];
    } else if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    } else {
        double submatrix[MAX][MAX];
        for (int x = 0; x < n; x++) {
            int subi = 0;
            for (int i = 1; i < n; i++) {
                int subj = 0;
                for (int j = 0; j < n; j++) {
                    if (j == x)
                        continue;
                    submatrix[subi][subj] = matrix[i][j];
                    subj++;
                }
                subi++;
            }
            det = det + (pow(-1, x) * matrix[0][x] * calculateDeterminant(submatrix, n - 1));
        }
    }
    return det;
}

void calculateCofactor(double matrix[MAX][MAX], double cofactorMatrix[MAX][MAX], int n) {
    double submatrix[MAX][MAX];
    for (int q = 0; q < n; q++) {
        for (int p = 0; p < n; p++) {
            int subi = 0;
            for (int i = 0; i < n; i++) {
                if (i == q)
                    continue;
                int subj = 0;
                for (int j = 0; j < n; j++) {
                    if (j == p)
                        continue;
                    submatrix[subi][subj] = matrix[i][j];
                    subj++;
                }
                subi++;
            }
            cofactorMatrix[q][p] = pow(-1, q + p) * calculateDeterminant(submatrix, n - 1);
        }
    }
}

void inverse(double matrix[MAX][MAX], double inverseMatrix[MAX][MAX], int n) {
    double cofactorMatrix[MAX][MAX];
    calculateCofactor(matrix, cofactorMatrix, n);

    // 転置をとる
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inverseMatrix[j][i] = cofactorMatrix[i][j];
        }
    }
}
