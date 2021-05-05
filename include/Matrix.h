#ifndef MATRIX_H
#define MATRIX_H

#include "Vector.h"

/// Matrix of size nxn(square)
template <typename T, const int size>
class Matrix
{
private:
    Vector<T, size> Array[size];

public:
    Matrix();
    Matrix(const std::initializer_list<Vector<T, size>> &elements);
    Matrix(const std::initializer_list<T> &elements);

    Vector<T, size> operator*(const Vector<T, size> &v) const;
    Matrix<T, size> operator*(const Matrix<T, size> &m) const;

    template <typename P, const int _size>
    friend std::ostream &operator<<(std::ostream &os, const Matrix<P, _size> &m);

    template <typename P, const int _size>
    friend bool operator==(const Matrix<P, _size> &m1, const Matrix<P, _size> &m2);

    Vector<T, size> operator[](int index) const; // operator for reading
    Vector<T, size> &operator[](int index);      // operator for setting
};

template <typename T, const int size>
Matrix<T, size>::Matrix()
{
    for (Vector<T, size> &element : Array)
        element = Vector<T, size>();
}

template <typename T, const int size>
Matrix<T, size>::Matrix(const std::initializer_list<Vector<T, size>> &elements)
{
    int index = 0;
    for (Vector<T, size> element : elements)
        Array[index++] = element;
}

template <typename T, const int size>
Matrix<T, size>::Matrix(const std::initializer_list<T> &elements)
{
    int k = 0;
    const std::vector<T> values = {elements}; // to have array[] acces for each element

    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
        {
            Array[i][j] = values[k];
            k++;
        }
}

template <typename T, const int size>
Vector<T, size> Matrix<T, size>::operator*(const Vector<T, size> &v) const
{
    std::vector<T> list;

    for (int i = 0; i < size; ++i)
    {
        list.push_back(this->Array[i] * v); // Vector * Vector = scalar value
    }

    return (Vector<T, size>({list}));
}

template <typename T, const int size>
Matrix<T, size> Matrix<T, size>::operator*(const Matrix<T, size> &m) const
{
    /// CLASSICAL ALGORITHM OF MATRIX MULTIPLICATION
    /// O(n^3)
    int i, j, k;
    Matrix<T, size> result;
    for (i = 0; i < size; ++i)
        for (j = 0; j < size; ++j)
            for (k = 0; k < size; ++k)
            {
                result[i][j] += (*this)[i][k] * m[k][j];
            }
    return result;
}

template <typename P, const int _size>
std::ostream &operator<<(std::ostream &os, const Matrix<P, _size> &m)
{
    for (int i = 0; i < _size; ++i)
    {
        os << m.Array[i];
        os << std::endl;
    }

    return os;
}

template <typename P, const int _size>
bool operator==(const Matrix<P, _size> &m1, const Matrix<P, _size> &m2)
{
    for (int i = 0; i < _size; ++i)
    {
        if (!(m1.Array[i] == m2.Array[i]))
            return false;
    }
    return true;
}

template <typename T, const int size>
Vector<T, size> Matrix<T, size>::operator[](int index) const
{
    if (index < 0 || index > size - 1)
        throw std::invalid_argument("Index out of range");
    else
    {
        return Array[index]; // return copy,which let's us only to read the value
    }
}

template <typename T, const int size>
Vector<T, size> &Matrix<T, size>::operator[](int index)
{
    if (index < 0 || index > size - 1)
        throw std::invalid_argument("Index out of range");
    else
    {
        return Array[index]; // return reference,which let's us set the value
    }
}

#endif // MATRIX_H