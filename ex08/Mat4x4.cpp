#include <cstring>
#include <iostream>
#include <cmath>
#include "Mat4x4.h"
#define SofM 4
using namespace std;

Mat4x4::Mat4x4()
{
    mat[0][0] = 1.0;
    mat[0][1] = 0.0;
    mat[0][2] = 0.0;
    mat[0][3] = 0.0;
    mat[1][0] = 0.0;
    mat[1][1] = 1.0;
    mat[1][2] = 0.0;
    mat[1][3] = 0.0;
    mat[2][0] = 0.0;
    mat[2][1] = 0.0;
    mat[2][2] = 1.0;
    mat[2][3] = 0.0;
    mat[3][0] = 0.0;
    mat[3][1] = 0.0;
    mat[3][2] = 0.0;
    mat[3][3] = 1.0;
}

Mat4x4::Mat4x4(const double coefficients[SofM][SofM])
{
    for (int i = 0; i < SofM; i++)
    {
        for (int j = 0; j < SofM; j++)
        {
            mat[i][j] = coefficients[i][j];
        }
    }
}

Mat4x4::~Mat4x4() {}

// 代入
Mat4x4 &Mat4x4::operator=(const Mat4x4 &other)
{
    for (int i = 0; i < SofM; ++i)
    {
        for (int j = 0; j < SofM; ++j)
        {
            mat[i][j] = other.mat[i][j];
        }
    }
    return *this;
}

//　アクセス
double &Mat4x4::operator()(int i, int j)
{
    return mat[i][j];
}
double Mat4x4::operator()(int i, int j) const
{
    return mat[i][j];
}



// A + B
Mat4x4 &Mat4x4::operator+=(const Mat4x4 &other)
{
    for (int i = 0; i < SofM; ++i)
    {
        for (int j = 0; j < SofM; ++j)
        {
            mat[i][j] = mat[i][j] + other.mat[i][j];
        }
    }
    return *this;
}

Mat4x4 &Mat4x4::operator-=(const Mat4x4 &other)
{
    for (int i = 0; i < SofM; ++i)
    {
        for (int j = 0; j < SofM; ++j)
        {
            mat[i][j] = mat[i][j] - other.mat[i][j];
        }
    }
    return *this;
}

Mat4x4 &Mat4x4::operator*=(const Mat4x4 &other)
{
    Mat4x4 c = *this;
    for (int i = 0; i < SofM; ++i)
    {
        for (int j = 0; j < SofM; ++j)
        {
            mat[i][j] = 0.0;
            for (int k = 0; k < SofM; ++k)
            {
                mat[i][j] += c.mat[i][k] * other.mat[k][j];
            }
        }
    }
    return *this;
}



// C = A + B
Mat4x4 operator+(const Mat4x4 &matA, const Mat4x4 &matB)
{
    return Mat4x4(matA) += matB;
}

Mat4x4 operator-(const Mat4x4 &matA, const Mat4x4 &matB)
{
    return Mat4x4(matA) -= matB;
}

Mat4x4 operator*(const Mat4x4 &matA, const Mat4x4 &matB)
{
    return Mat4x4(matA) *= matB;
}



//比較
bool operator==(const Mat4x4 &matA, const Mat4x4 &matB)
{
    for (int i = 0; i < SofM; ++i)
    {
        for (int j = 0; j < SofM; ++j)
        {

            if (matA(i, j) != matB(i, j))
                return false;
        }
    }
    return true;
}

//ストリーム挿入
std::ostream &operator<<(std::ostream &os, const Mat4x4 &c)
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            os << c.mat[i][j] << " ";
        }
        os << endl;
    }

    return os;
}


// -A
const Mat4x4 Mat4x4::operator-()
{
    Mat4x4 result;
    for (int i = 0; i < SofM; ++i)
    {
        for (int j = 0; j < SofM; ++j)
        {
            if (mat[i][j] != 0)
            {
                result.mat[i][j] = -mat[i][j];
            }
        }
    }
    return result.mat;
}