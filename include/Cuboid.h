#ifndef CUBOID_H
#define CUBOID_H

#include "Matrix3x3.h"
#include "Vector3D.h"
#include <fstream>
#include <iomanip>
#include <string>

constexpr unsigned int SIZE = 8;

enum File_mode
{
    Overwrite,
    Append
};

class Cuboid
{
private:
    Vector3D vertices[SIZE];

public:
    Cuboid();
    Cuboid(double x1, double y1, double z1, double x2, double y2, double z2);
    Cuboid(std::vector<Vector3D> &vectors);

    Cuboid Rotation(Matrix3x3 &rotation_matrix);
    Cuboid Translate(Vector3D translation_vector);
    Cuboid Scale(double scalar);
    void Side_length() const;

    friend std::ostream &operator<<(std::ostream &os, const Cuboid &c);
    friend std::ofstream &operator<<(std::ofstream &ofs, const Cuboid &c);
    friend bool operator==(const Cuboid &c1, const Cuboid &c2);

    void Write_to_file(std::string filename, File_mode mode) const;

    Vector3D operator[](int index) const; // operator for reading
    Vector3D &operator[](int index);      // operator for setting
};

#endif // CUBOID_H