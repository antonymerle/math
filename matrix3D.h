#ifndef MATRIX3D_H
#define MATRIX3D_H
#include "vector3D.h"
#include <iomanip>
#include <iostream>

/*

 row-major order [C][R]
 O 3 6
 1 4 7
 2 5 8

 column-major order [R][C]
 0 1 2
 3 4 5
 6 7 8

*/

struct Matrix3D
{
  private:
    float n[3][3];

  public:
    // Matrix3D() : n{} {}; // zero initialization;

    // identity matrix
    // clang-format off
    Matrix3D()
    {
        n[0][0] = 1.0f; n[0][1] = 0.0f; n[0][2] = 0.0f;  // 1 0 0
        n[1][0] = 0.0f; n[1][1] = 1.0f; n[1][2] = 0.0f;  // 0 1 0
        n[2][0] = 0.0f; n[2][1] = 0.0f; n[2][2] = 1.0f;  // 0 0 1
    }
    // clang-format on

    // column major notation constructors
    // [C][R] to [R][C]
    // clang-format off
  Matrix3D(float n00, float n01, float n02, // 0 3 6
           float n10, float n11, float n12, // 1 4 7
           float n20, float n21, float n22) // 6 7 8
    {
        n[0][0] = n00; n[0][1] = n10; n[0][2] = n20; // 0 1 2
        n[1][0] = n01; n[1][1] = n11; n[1][2] = n21; // 3 4 5
        n[2][0] = n02; n[2][1] = n12; n[2][2] = n22; // 6 7 8 
    }

  Matrix3D(const Vector3D& a, const Vector3D& b, const Vector3D& c)
    {
        n[0][0] = a.x; n[0][1] = a.y; n[0][2] = a.z; // 0 1 2
        n[1][0] = b.x; n[1][1] = b.y; n[1][2] = b.z; // 3 4 5
        n[2][0] = c.x; n[2][1] = c.y; n[2][2] = c.z; // 6 7 8   
    }
    // clang-format on

    float& operator()(int i, int j)
    {
        return n[j][i];
    }

    const float& operator()(int i, int j) const
    {
        return n[j][i];
    }

    Vector3D& operator[](int j)
    {
        return reinterpret_cast<Vector3D&>(n[j]);
    }

    const Vector3D& operator[](int j) const
    {
        return reinterpret_cast<const Vector3D&>(n[j]);
    }

    void print() const
    {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "┌                         ┐\n";
        for (int i = 0; i < 3; ++i)
        {
            std::cout << "│ ";
            for (int j = 0; j < 3; ++j)
            {
                std::cout << std::setw(7) << n[j][i] << " ";
            }
            std::cout << "│\n";
        }
        std::cout << "└                         ┘\n";
    }

    void print_col(const int i) const
    {
        (*this)[i].print();
    }
};

// clang-format off
inline Matrix3D operator*(const Matrix3D& A, const Matrix3D& B)
{
      return (Matrix3D(A(0,0) * B(0,0) + A(0,1) * B(1,0) + A(0,2) * B(2,0),
                       A(0,0) * B(0,1) + A(0,1) * B(1,1) + A(0,2) * B(2,1),
                       A(0,0) * B(0,2) + A(0,1) * B(1,2) + A(0,2) * B(2,2),

                       A(1,0) * B(0,0) + A(1,1) * B(1,0) + A(1,2) * B(2,0),
                       A(1,0) * B(0,1) + A(1,1) * B(1,1) + A(1,2) * B(2,1),
                       A(1,0) * B(0,2) + A(1,1) * B(1,2) + A(1,2) * B(2,2),

                       A(2,0) * B(0,0) + A(2,1) * B(1,0) + A(2,2) * B(2,0),
                       A(2,0) * B(0,1) + A(2,1) * B(1,1) + A(2,2) * B(2,1),
                       A(2,0) * B(0,2) + A(2,1) * B(1,2) + A(2,2) * B(2,2)));
}
// clang-format on

#endif
