//
// Created by Max Rosoff on 1/29/20.
//

#include "Vector3D.h"

using namespace std;

Vector3D::Vector3D(int size)
{
    data.resize(size);
}

Vector3D::Vector3D(const initializer_list<double> &il)
{
    *this = il;
}

Vector3D &Vector3D::operator=(const initializer_list<double> &il)
{
    data.resize(il.size());
    copy(il.begin(), il.end(), data.begin());
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Vector3D &other)
{
    out << "{";

    size_t i = 0;

    for(i = 0; i < other.size() - 1; i++)
    {
        out << other[i] << ", ";
    }

    out << other[i] << "}";

    return out;
}
