//
// Created by Max Rosoff on 1/29/20.
//

#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <iostream>

#include <vector>
#include <initializer_list>

#include <algorithm>
#include <cmath>
#include <random>


class Vector3D {

    public:

        Vector3D() = default;
        Vector3D(const Vector3D &) = default;
        Vector3D &operator=(const Vector3D &) = default;
        ~Vector3D() = default;

        explicit Vector3D(int);
        Vector3D(const std::initializer_list<double> &);
        Vector3D &operator=(const std::initializer_list<double> &);

        inline size_t size() const
        {
            return data.size();
        }

        inline double operator[](const int i) const
        {
            return data[i];
        }

        inline double &operator[](const int i)
        {
            return data[i];
        }

        inline Vector3D operator-() const
        {
            Vector3D newVector(data.size());

            for(size_t i = 0; i < data.size(); i++)
            {
                newVector[i] = -data[i];
            }

            return newVector;
        }

        inline Vector3D operator+(const Vector3D &other) const
        {
            Vector3D newVector(data.size());

            for(size_t i = 0; i < data.size(); i++)
            {
                newVector[i] = data[i] + other[i];
            }

            return newVector;
        }

        inline Vector3D operator-(const Vector3D &other) const
        {
            Vector3D newVector(data.size());

            for(size_t i = 0; i < data.size(); i++)
            {
                newVector[i] = data[i] - other[i];
            }

            return newVector;
        }

        inline Vector3D operator*(const Vector3D &other) const
        {
            Vector3D newVector(data.size());

            for(size_t i = 0; i < data.size(); i++)
            {
                newVector[i] = data[i] * other[i];
            }

            return newVector;
        }

        inline Vector3D &operator+=(const Vector3D &other)
        {
            *this = operator+(other);
            return *this;
        }

        inline Vector3D &operator-=(const Vector3D &other)
        {
            *this = operator-(other);
            return *this;
        }

        inline Vector3D &operator*=(const Vector3D &other)
        {
            *this = operator*(other);
            return *this;
        }

        inline Vector3D operator*(const double scalar) const
        {
            Vector3D newVector(data.size());

            for(size_t i = 0; i < data.size(); i++)
            {
                newVector[i] = data[i] * scalar;
            }

            return newVector;
        }

        inline Vector3D operator/(const double scalar) const
        {
            return operator*(1 / scalar);
        }

        inline Vector3D &operator*=(const double scalar)
        {
            *this = operator*(scalar);
            return *this;
        }

        inline Vector3D &operator/=(const double scalar)
        {
            *this = operator/(scalar);
            return *this;
        }

        inline bool operator==(const Vector3D &other) const
        {
            for(size_t i = 0; i < data.size(); i++)
            {
                if (data[i] != other[i]) 
                {
                    return false;
                }
            }

            return true;
        }

        inline bool operator!=(const Vector3D &other) const
        {
            return !operator==(*this);
        }

        inline double length() const
        {
            return sqrt(this->dot(*this));
        }

        inline Vector3D normalize() const
        {
            return *this / length();
        }

        inline double dot(const Vector3D &other) const
        {
            double sum = 0;

            for(size_t i = 0; i < data.size(); i++)
            {
                sum += data[i] * other[i];
            }

            return sum;
        }

        inline Vector3D cross(const Vector3D &other) const
        {
            return {data[1] * other[2] - data[2] * other[1],
                -(data[0] * other[2] - data[2] * other[0]),
                    data[0] * other[1] - data[1] * other[0]};
        }

    private:

        std::vector<double> data;
};

inline Vector3D operator*(double scalar, const Vector3D &other)
{
    return other * scalar;
}
    
static std::default_random_engine generator;

inline Vector3D makeRandomUnitVector()
{
    std::uniform_real_distribution<double> distribution;

    Vector3D returnVector(3);

    while (true)
    {
        for (int i = 0; i < 3; i++)
        {
            returnVector[i] = distribution(generator);
        }

        returnVector.normalize();

        if (returnVector.dot(returnVector) < 1)
        {
            return returnVector;
        }
    }
}

std::ostream &operator<<(std::ostream &, const Vector3D &);

using Point3D = Vector3D;
using Color = Vector3D;

#endif //VECTOR3D_H
