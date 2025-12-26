#include "matrix3D.h"
#include "vector3D.h"
#include <iostream>

int main()
{
    Vector3D v;

    std::cout << "Hello Mathématiques\n";
    std::cout << v[0] << " " << v[1] << " " << v[2] << " " << "\n";

    Matrix3D m;
    m.print();
    m.print_col(0);
    m.print_col(1);
    m.print_col(2);
}
