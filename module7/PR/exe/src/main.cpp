#include <iostream>

struct Matrix;

#ifdef __cplusplus
extern "C"
{
#endif
    extern Matrix* __declspec(dllimport) math_createMatrix(int, int);
    extern void __declspec(dllimport) math_deleteMatrix(Matrix *);
    extern double __declspec(dllimport) math_get(Matrix *, int, int);
    extern void __declspec(dllimport) math_set(Matrix *, int, int, double);
    extern void __declspec(dllimport) math_print(Matrix *);
#ifdef __cplusplus
}
#endif

int main()
{
    // не работает, т.к. к проекту подключена динамическая бибилиотека
    // math::Matrix m(3, 3);
    // m(0,0) = 1.;
    // m(1,1) = 1.;

    // работает
    Matrix *m1 = math_createMatrix(3, 3);

    math_set(m1, 0, 0, 1.);
    math_set(m1, 1, 1, 1.);
    math_print(m1);

    // в конце обязательно вызываем деструктор
    math_deleteMatrix(m1);

    return 0;
}