#include <cstddef>
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

inline Vector3D operator-(const Vector3D& v)
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

int main()
{
    Vector3D v;

    std::cout << "Hello Mathématiques\n";
    std::cout << v[0] << " " << v[1] << " " << v[2] << " " << "\n";
}
