#ifndef MATRIX3X3_H
#define MATRIX3X3_H

#include "Matrix.h"

typedef Matrix<double, 3> Matrix3x3;

void set_Rotation_OX(Matrix3x3 &m, double angle);
void set_Rotation_OY(Matrix3x3 &m, double angle);
void set_Rotation_OZ(Matrix3x3 &m, double angle);
#endif // MATRIX3X3_H