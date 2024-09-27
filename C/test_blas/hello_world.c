#include <stdio.h>
#include <cblas.h>

int main() {
    // 矩阵维度
    int m = 2; // A 矩阵的行数
    int n = 2; // B 矩阵的列数
    int k = 2; // A 矩阵的列数和 B 矩阵的行数

    // 定义矩阵 A 和 B
    double A[4] = {1.0, 2.0, 3.0, 4.0}; // 2x2 矩阵
    double B[4] = {1.0, 2.0, 3.0, 4.0}; // 2x2 矩阵
    double C[4] = {0.0, 0.0, 0.0, 0.0}; // 2x2 矩阵，用于存储结果


    // 使用 cblas_dgemm 进行矩阵乘法
    // cblas_dgemm(order, transA, transB, m, n, k, alpha, A, lda, B, ldb, beta, C, ldc)
    // order: 矩阵存储顺序（CblasRowMajor 或 CblasColMajor）
    // transA: 矩阵 A 是否转置（CblasNoTrans 或 CblasTrans）
    // transB: 矩阵 B 是否转置（CblasNoTrans 或 CblasTrans）
    // m: 矩阵 C 的行数
    // n: 矩阵 C 的列数
    // k: 矩阵 A 的列数和矩阵 B 的行数
    // alpha: 矩阵乘法中的缩放因子
    // A: 矩阵 A
    // lda: 矩阵 A 的列间距
    // B: 矩阵 B
    // ldb: 矩阵 B 的列间距
    // beta: 矩阵 C 的缩放因子
    // C: 矩阵 C
    // ldc: 矩阵 C 的列间距

    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 
                 m, n, k, 1.0, A, k, B, n, 0.0, C, n);

    // 打印结果矩阵
    printf("left matrix A:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%f ", A[i * n + j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("right matrix B:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%f ", A[i * n + j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Result matrix C:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%f ", C[i * n + j]);
        }
        printf("\n");
    }

    return 0;
}
