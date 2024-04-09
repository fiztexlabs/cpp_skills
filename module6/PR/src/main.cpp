#include <src/matrix.h>
#include <iostream>

int main()
{
    math::Matrix M1;

    std::cout << "Enter dimensions of the matrix" << std::endl;
    std::cin >> M1;

    math::Matrix M2(M1);
    for (int i = 0; i < M2.rows(); ++i)
        for (int j = 0; j < M2.cols(); ++j)
            M2(i, j) += 2.;

    std::cout << "matrix M1: \n"
              << M1 << "\n matrix M2: \n"
              << M2 << std::endl;

    M1 += M2;
    std::cout << "Add M2 to M1: \n"
              << M1 << std::endl;

    M1 *= 2.;
    std::cout << "Multiply M1 on 2: \n"
              << M1 << std::endl;

    return 0;
}