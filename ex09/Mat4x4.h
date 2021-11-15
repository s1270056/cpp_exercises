#ifndef Mat4x4_H
#define Mat4x4_H
#include <string>
#include <istream>
#include <ostream>
#include <cstdlib>
using namespace std;

template <class T, int N>
class Mat4x4
{
public:
  // defolt
  Mat4x4()
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
  // double
  Mat4x4(const T coefficients[N][N])
  {
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        mat[i][j] = coefficients[i][j];
      }
    }
  }

  // destructor
  ~Mat4x4(){};
  //　代入
  Mat4x4 &operator=(const Mat4x4 &other)
  {
    for (int i = 0; i < N; ++i)
    {
      for (int j = 0; j < N; ++j)
      {
        mat[i][j] = other.mat[i][j];
      }
    }
    return *this;
  }

  //　アクセス
  T &operator()(int i, int j)
  {
    return mat[i][j];
  }
  T operator()(int i, int j) const
  {
    return mat[i][j];
  }

  // A + B
  Mat4x4 &operator+=(const Mat4x4 &other)
  {
    for (int i = 0; i < N; ++i)
    {
      for (int j = 0; j < N; ++j)
      {
        mat[i][j] = mat[i][j] + other.mat[i][j];
      }
    }
    return *this;
  }
  Mat4x4 &operator-=(const Mat4x4 &other)
  {
    for (int i = 0; i < N; ++i)
    {
      for (int j = 0; j < N; ++j)
      {
        mat[i][j] = mat[i][j] - other.mat[i][j];
      }
    }
    return *this;
  }
  Mat4x4 &operator*=(const Mat4x4 &other)
  {
    Mat4x4 c = *this;
    for (int i = 0; i < N; ++i)
    {
      for (int j = 0; j < N; ++j)
      {
        mat[i][j] = 0.0;
        for (int k = 0; k < N; ++k)
        {
          mat[i][j] += c.mat[i][k] * other.mat[k][j];
        }
      }
    }
    return *this;
  }

  //ストリーム挿入
  friend ostream &operator<<(ostream &os, const Mat4x4 &c){
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
  const Mat4x4 operator-()
  {
    Mat4x4 result;
    for (int i = 0; i < N; ++i)
    {
      for (int j = 0; j < N; ++j)
      {
        if (mat[i][j] != 0)
        {
          result.mat[i][j] = -mat[i][j];
        }
      }
    }
    return result.mat;
  }

private:
  T mat[N][N];
};

// C = A + B
template <class T, int N>
Mat4x4<T, N> operator+(const Mat4x4<T, N> &matA, const Mat4x4<T, N> &matB)
{
  return Mat4x4<T, N>(matA) += matB;
}
template <class T, int N>
Mat4x4<T, N> operator-(const Mat4x4<T, N> &matA, const Mat4x4<T, N> &matB)
{
  return Mat4x4<T, N>(matA) -= matB;
}
template <class T, int N>
Mat4x4<T, N> operator*(const Mat4x4<T, N> &matA, const Mat4x4<T, N> &matB)
{
  return Mat4x4<T, N>(matA) *= matB;
}
// 比較
template <class T, int N>
bool operator==(const Mat4x4<T, N> &matA, const Mat4x4<T, N> &matB)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {

            if (matA(i, j) != matB(i, j))
                return false;
        }
    }
    return true;
}




#endif