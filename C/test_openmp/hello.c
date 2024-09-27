#include<stdio.h>
#include<omp.h>
#include<math.h>
#include<time.h>
void test_shared()
{  
    int num_threads;
    #pragma omp parallel
    {
        num_threads = omp_get_num_threads();
    }
    // 单线程
    double pi = 0.0;
    double  start, end;
    start = omp_get_wtime();
    for (int i = 0; i < 10000000; i++) {
        // Leibniz series: Pi = 4 * (1 - 1/3 + 1/5 - 1/7 + 1/9 - ...)
        pi += pow(-1, i) / (2.0 * i + 1.0);
    }
    end = omp_get_wtime();
    printf("Single thread PI: %.5e, Time used: %.4fs\n",(pi* 4.0),(end-start));
    
    // 多线程但是无局部变量无原子操作

    pi = 0.0;
    start = omp_get_wtime();

        #pragma omp parallel for 
        for (int i = 0; i < 10000000; i++) {
            // Leibniz series: Pi = 4 * (1 - 1/3 + 1/5 - 1/7 + 1/9 - ...)
            #pragma omp atomic
            pi += pow(-1, i) / (2.0 * i + 1.0);
        }


    end = omp_get_wtime();

    printf("%d thread1 PI: %.5e, Time used: %.4fs\n",num_threads,(pi* 4.0),(end-start));
    
    // 多线程 添加局部变量以及原子操作
    pi = 0.0;
    start = omp_get_wtime();

    #pragma omp parallel
    {
        double local_pi = 0.0; // 每个线程的局部变量
        #pragma omp for
        for (int i = 0; i < 10000000; i++) {
            local_pi += pow(-1, i) / (2.0 * i + 1.0);
        }
        #pragma omp atomic
        pi += local_pi; // 汇总每个线程的局部结果
    }

    end = omp_get_wtime();
    printf("%d thread2 PI: %.5e, Time used: %.4fs\n",num_threads,(pi* 4.0),(end-start));

    // 多线程 归约
    // 归约操作会将每个线程计算得到的pi的值相加，最终得到一个总的pi值。
        pi = 0.0;
    start = omp_get_wtime();

    #pragma omp parallel for reduction(+:pi) // 使用归约
    for (int i = 0; i < 10000000; i++) {
        pi += pow(-1, i) / (2.0 * i + 1.0);
    }

    end = omp_get_wtime();
    printf("%d thread3 PI: %.5e, Time used: %.4fs\n",num_threads,(pi* 4.0),(end-start));
}


int main()
{
    test_shared();
    return 0;
}