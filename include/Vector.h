#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <initializer_list>
#include <cmath>
#include <vector>

constexpr double MIN_DIFF = 0.0000000001;

template <typename T, const int size>
class Vector
{
private:
    T Components[size];

public:
    Vector();
    Vector(const std::initializer_list<T> &elements);
    Vector(const std::vector<T> &elements);

    Vector<T, size> operator+(const Vector<T, size> &v2) const;
    Vector<T, size> operator-(const Vector<T, size> &v2) const;
    Vector<T, size> operator*(const double scalar) const; // scalar multiplication from the right
    double operator*(const Vector<T, size> &v2) const;
    double Length() const;

    template <typename P, const int _size>
    friend bool operator==(const Vector<P, _size> &v1, const Vector<P, _size> &v2);

    template <typename P, const int _size>
    friend std::ostream &operator<<(std::ostream &os, const Vector<P, _size> &v);

    template <typename P, const int _size>
    friend std::istream &operator>>(std::istream &is, Vector<P, _size> &v);

    T operator[](int index) const; // operator for reading
    T &operator[](int index);      // operator for setting
};

template <typename T, const int size>
Vector<T, size>::Vector()
{
    for (T &element : Components) // initialize each element with default value = 0
        element = 0;
}

template <typename T, const int size>
Vector<T, size>::Vector(const std::initializer_list<T> &elements) //: Vector()
{
    int index = 0;
    for (T element : elements)
        Components[index++] = element;
}

template <typename T, const int size>
Vector<T, size>::Vector(const std::vector<T> &elements) //: Vector()
{
    int index = 0;
    if (elements.size() > size || elements.size() < size)
        throw std::invalid_argument("Wrong parameters-Vector initialization");
    for (T element : elements)
        Components[index++] = element;
}

template <typename T, const int size>
Vector<T, size> Vector<T, size>::operator+(const Vector<T, size> &v2) const
{
    Vector<T, size> result;

    for (int i = 0; i < size; ++i)
    {
        result.Components[i] = this->Components[i] + v2.Components[i];
    }
    return result;
}

template <typename T, const int size>
Vector<T, size> Vector<T, size>::operator-(const Vector<T, size> &v2) const
{
    Vector<T, size> result;

    for (int i = 0; i < size; ++i)
    {
        result.Components[i] = this->Components[i] - v2.Components[i];
    }
    return result;
}

template <typename T, const int size>
Vector<T, size> Vector<T, size>::operator*(const double scalar) const
{
    Vector<T, size> result;
    for (int i = 0; i < size; ++i)
    {
        result.Components[i] = this->Components[i] * scalar;
    }
    return result;
}

template <typename T, const int size>
double Vector<T, size>::operator*(const Vector<T, size> &v2) const
{
    double result = 0;
    for (int i = 0; i < size; ++i)
    {
        result += this->Components[i] * v2.Components[i];
    }
    return result;
}

template <typename T, const int size>
double Vector<T, size>::Length() const
{
    T pre_result = 0;
    double result;

    for (int i = 0; i < size; ++i)
    {
        pre_result += Components[i] * Components[i]; // x*x y*y z*z etc.
    }

    result = sqrt(pre_result);
    return result;
}

template <typename P, const int _size>
bool operator==(const Vector<P, _size> &v1, const Vector<P, _size> &v2)
{
    for (int i = 0; i < _size; ++i)
    {
        if (std::abs(v1.Components[i] - v2.Components[i]) > MIN_DIFF)
            return false;
    }
    return true;
}

template <typename P, const int _size>
std::ostream &operator<<(std::ostream &os, const Vector<P, _size> &v)
{
    int i = 0;

    for (i; i < _size - 1; ++i)
        os << v.Components[i] << "\t"; // separate each element with a tab

    os << v.Components[i]; // last element printed outside of the loop to avoid additional tab e.g. "x "

    return os;
}

template <typename P, const int _size>
std::istream &operator>>(std::istream &is, Vector<P, _size> &v)
{
    for (int i = 0; i < _size; ++i)
    {
        is >> v.Components[i];
        if (is.fail())
        {
            throw std::invalid_argument("Invalid argument passed while reading vector");
            break;
        }
    }
    return is;
}

template <typename T, const int size>
T Vector<T, size>::operator[](int index) const
{
    if (index < 0 || index > size - 1)
        throw std::invalid_argument("Index out of range"); // return copy,which let's us only to read the value
    else
    {
        return Components[index];
    }
}

template <typename T, const int size>
T &Vector<T, size>::operator[](int index)
{
    if (index < 0 || index > size - 1)
        throw std::invalid_argument("Index out of range");
    else
    {
        return Components[index]; // return reference,which let's us set the value
    }
}

#endif //VECTOR_H