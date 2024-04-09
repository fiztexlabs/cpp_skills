#include <matrixlib/matrix.h>

int main()
{
    math::Matrix m(3, 3);
    m(0,0) = 1.;
    m(1,1) = 1.;

    math::Matrix m1(3, 3);
    m1(0,0)=5.;
    m1(1,1)=5.;

    std::cout << "Matrix m is:\n" << m << std::endl;

    std::cout << "Matrix m1 is:\n" << m1 << std::endl;

    math::Matrix m2 = m + m1;
    std::cout << "Sum of matrices m and m1 is:\n" << m2 << std::endl;

    math::Matrix m3 = m - m1;
    std::cout << "Subtract of matrices m and m1 is:\n"  << m3 << std::endl;

    math::Matrix m4 = m * m1;
    std::cout << "Multiplication of matrices m and m1 is:\n" << m4 << std::endl;

    return 0;
}