#include <iostream>
#include <Eigen/Dense>

using Eigen::MatrixXd;

int main() {
    // 创建一个 2x2 的矩阵
    MatrixXd m(2, 2);
    
    // 初始化矩阵的元素
    m(0, 0) = 3;
    m(1, 0) = 2.5;
    m(0, 1) = -1;
    m(1, 1) = m(1, 0) + m(0, 1); // 计算 m(1, 1) 的值

    // 输出矩阵
    std::cout << m << std::endl;

    return 0;
}