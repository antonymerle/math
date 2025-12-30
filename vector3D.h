#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <cmath>
#include <cstddef>
#include <iomanip>
#include <iostream>

struct Vector3D
{
    float x, y, z;
    Vector3D(float x = 0.0f, float y = 0.0f, float z = 0.0f) : x{x}, y{y}, z{z} {};

    float& operator[](std::size_t i)
    {
        return (&x)[i];
    }

    const float& operator[](std::size_t i) const
    {
        return (&x)[i];
    }

    Vector3D& operator*=(float s)
    {
        x *= s;
        y *= s;
        z *= s;

        return (*this);
    };

    Vector3D& operator/=(float s)
    {
        s = 1.0f / s;
        x *= s;
        y *= s;
        z *= s;

        return (*this);
    };

    Vector3D& operator+=(const Vector3D& v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        return (*this);
    }

    Vector3D& operator-=(const Vector3D& v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return (*this);
    }

    void print() const
    {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "┌       ┐\n";
        std::cout << "│ " << std::setw(5) << x << " │\n";
        std::cout << "│ " << std::setw(5) << y << " │\n";
        std::cout << "│ " << std::setw(5) << z << " │\n";
        std::cout << "└       ┘\n";
    }
};

inline Vector3D operator*(const Vector3D& v, float s)
{
    return Vector3D(v.x * s, v.y * s, v.z * s);
}

inline Vector3D operator/(const Vector3D& v, float s)
{
    s = 1.0f / s;
    return Vector3D(v.x * s, v.y * s, v.z * s);
}

inline Vector3D operator-(const Vector3D& v) // unary operator
{
    return Vector3D(-v.x, -v.y, -v.z);
}

inline float Magnitude(const Vector3D& v)
{
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

inline Vector3D Normalize(const Vector3D& v)
{
    return v / Magnitude(v);
}

inline Vector3D operator+(const Vector3D& a, const Vector3D& b)
{
    return Vector3D(a.x + b.x, a.y + b.y, a.z + b.z);
}

inline Vector3D operator-(const Vector3D& a, const Vector3D& b)
{
    return Vector3D(a.x - b.x, a.y - b.y, a.z - b.z);
}

inline float Dot(const Vector3D& a, const Vector3D& b)
{
    return (a.x * b.x + a.y * b.y + a.z * b.z);
}

#endif
