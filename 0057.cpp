#include <stdio.h>
#include <math.h>

void inverse(double matrix[1000][1000], int n);
void calculateCofactor(double matrix[1000][1000], double cofactorMatrix[1000][1000], int n); // Define the missing function
double calculateDeterminant(double matrix[1000][1000], int n);
double inverseMatrix[1000][1000] = {};

int main(){
    int n;
    printf("n×n行列式のnの代入(n>5): ");
    scanf("%d", &n);

    double matrix[1000][1000] = {};

    printf("行列の成分の代入（行にそって）:\r\n");
    // matix読み込み
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }

    // n×n matrixからdeterminantを計算
    //N=4のとき,inversematrixまでを求める
    double determinant = calculateDeterminant(matrix, n);

    // 正則判定
    /*if (determinant == 0) {
        printf("逆行列は存在しない\r\n");
        return 0.0;
    }*/

    //余因子行列の計算
    //double cofactorMatrix[1000][1000] = {};
    //calculateCofactor(matrix,n);

    // Print the inverse matrix
    printf("求める逆行列:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {//各成分ごとに余因子行列成分÷行列式
            //inverseMatrix[i][j] = cofactorMatrix[i][j] / determinant;
            printf("%lf ", inverseMatrix[i][j]);
        }
        printf("\n");
    }

}



double calculateDeterminant(double matrix[1000][1000], int n) {//n=4のみ

    double det = 0.0;
    /*if (n == 1) {//まんま
        return matrix[0][0];
    } else if (n == 2) {//ad-bc
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    } else if (n == 3){//さらす
        return matrix[0][0] * matrix[1][1] * matrix[2][2] + matrix[0][1] * matrix[1][2] * matrix[2][0] + matrix[0][2] * matrix[1][0] * matrix[2][1] - matrix[0][2] * matrix[1][1] * matrix[2][0] - matrix[0][1] * matrix[1][0] * matrix[2][2] - matrix[0][0] * matrix[1][2] * matrix[2][1];
    } else if (n == 4){*/
            double tempmatrix[1000][1000];
            for(int k=0;k<4;k++){
                for(int l=0;l<4;l++){
                    for(int i=0;i<3;i++){
                        for(int j=0;j<3;j++){
                            if(i!=k && i!=l && j!=l && j!=k){
                                tempmatrix[i][j] = matrix[k][l];
                            }
                        }
                    }
                //tempmatrix[k][l]に関する余因子行列が求まった
                det += pow(-1.0, k+l) * matrix[k][l] * calculateDeterminant(tempmatrix, 3);
                inverseMatrix[k][l] = pow(-1.0, k+l) * calculateDeterminant(tempmatrix, 3);
                }
            }
        //return det
        return det;
    //}
        /*else if (n == 4) {
                for (int p = 0; p < n; p++) {
                    double tempMatrix[3][3];
                    int i1 = 0, j1 = 0;
                    for (int i = 0; i < n; i++) {
                        if (i == p) {
                            continue;
                        }
                        for (int j = 0; j < n; j++) {
                            if (j == 0) {
                                continue;
                            }
                            tempMatrix[i1][j1] = matrix[i][j];
                            j1++;
                        }
                        i1++;
                        j1 = 0;
                    }
                    det += pow(-1.0, p) * matrix[0][p] * calculateDeterminant(tempMatrix, n - 1);
                }
            }
    return det;*/
}

/*void calculateCofactor(double matrix[1000][1000], double cofactorMatrix[1000][1000], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Create a submatrix by removing the i-th row and j-th column
            double submatrix[1000][1000];
            int p = 0, q = 0;
            for (int row = 0; row < n; row++) {
                if (row == i) continue;
                for (int col = 0; col < n; col++) {
                    if (col == j) continue;
                    submatrix[p][q] = matrix[row][col];
                    q++;
                }
                p++;
                q = 0;
            }

            // Calculate the determinant of the submatrix
            double submatrixDeterminant = calculateDeterminant(submatrix, n - 1);

            // Calculate the cofactor
            cofactorMatrix[i][j] = pow(-1, i + j) * submatrixDeterminant;
        }
    }
}*/