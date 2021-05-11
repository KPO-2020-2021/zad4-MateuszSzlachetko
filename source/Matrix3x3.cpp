#include "Matrix3x3.h"

void set_Rotation_OX(Matrix3x3 &m, double angle)
{
    double sin_a, cos_a;
    sin_a = sin(angle * M_PI / 180); // M_PI 0. x20
    cos_a = cos(angle * M_PI / 180);

    m = Matrix3x3({1, 0, 0, 0, cos_a, -sin_a, 0, sin_a, cos_a});
}
void set_Rotation_OY(Matrix3x3 &m, double angle)
{
    double sin_a, cos_a;
    sin_a = sin(angle * M_PI / 180); // M_PI 0. x20
    cos_a = cos(angle * M_PI / 180);

    m = Matrix3x3({cos_a, 0, sin_a, 0, 1, 0, -sin_a, 0, cos_a});
}
void set_Rotation_OZ(Matrix3x3 &m, double angle)
{
    double sin_a, cos_a;
    sin_a = sin(angle * M_PI / 180); // M_PI 0. x20
    cos_a = cos(angle * M_PI / 180);

    m = Matrix3x3({cos_a, -sin_a, 0, sin_a, cos_a, 0, 0, 0, 1});
}

void RotXYZ_translate(Matrix4x4 &m, double a, double b, double g, Vector3D translation)
{
    // calculate all angles
    double sin_a, cos_a;
    sin_a = sin(a * M_PI / 180);
    cos_a = cos(a * M_PI / 180);

    double sin_b, cos_b;
    sin_b = sin(b * M_PI / 180);
    cos_b = cos(b * M_PI / 180);

    double sin_g, cos_g;
    sin_g = sin(g * M_PI / 180);
    cos_g = cos(g * M_PI / 180);

    // set matrix from the formula

    m = Matrix4x4({cos_a * cos_b, cos_a * sin_b * sin_g - sin_a * cos_g, cos_a * sin_b * cos_g + sin_a + sin_g, translation[0],
                   sin_a * cos_b, sin_a * sin_b * sin_g + cos_a * cos_g, sin_a * sin_b * cos_g - cos_a * sin_g, translation[1],
                   -sin_b, cos_b * sin_g, cos_b * cos_g, translation[2],
                   0, 0, 0, 1});

    // Show created matrix

    std::cout << std::fixed;
    std::cout << m << std::endl;
}