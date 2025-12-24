#ifndef MATRIX3D_H
#define MATRIX3D_H
#include "vector3D.h"

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
    Matrix3D() = default;

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
};

#endif
