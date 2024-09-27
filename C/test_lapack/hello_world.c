#include <stdio.h>
#include <stdlib.h>
#include <lapacke.h>

int main() {
    // 定义矩阵 A
    double A[3][3] = {
        {1, 2, 3},
        {0, 1, 4},
        {5, 6, 0}
    };

    // 复制矩阵 A 到 B，因为 LAPACK 会修改原矩阵
    double B[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            B[i][j] = A[i][j];

    // 定义工作数组
    int ipiv[3];
    int info;

    // 使用 LAPACKE_dgetrf 进行 LU 分解
    info = LAPACKE_dgetrf(LAPACK_ROW_MAJOR, 3, 3, &B[0][0], 3, ipiv);
    if (info != 0) {
        printf("Error in LU factorization: %d\n", info);
        return info;
    }

    // 使用 LAPACKE_dgetri 计算逆矩阵
    info = LAPACKE_dgetri(LAPACK_ROW_MAJOR, 3, &B[0][0], 3, ipiv);
    if (info != 0) {
        printf("Error in matrix inversion: %d\n", info);
        return info;
    }

    // 打印逆矩阵
    printf("Inverse Matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%lf ", B[i][j]);
        }
        printf("\n");
    }

    return 0;
}
