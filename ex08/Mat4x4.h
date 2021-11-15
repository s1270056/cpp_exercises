#ifndef Mat4x4_H
#define Mat4x4_H
#include <string>
#include <istream>
#include <ostream>
#include <cstdlib>
using namespace std;

class Mat4x4
{
public:
  // defolt
  Mat4x4();
  // double
  Mat4x4(const double coefficients[4][4]);

  // destructor
  ~Mat4x4();
  //　代入
  Mat4x4 &operator=(const Mat4x4 &mat);

  //　アクセス
  double &operator()(int i, int j);
  double operator()(int i, int j) const;

  // A + B
  Mat4x4 &operator+=(const Mat4x4 &mat);
  Mat4x4 &operator-=(const Mat4x4 &mat);
  Mat4x4 &operator*=(const Mat4x4 &mat);

  //ストリーム挿入
  friend ostream &operator<<(ostream &os, const Mat4x4 &c);
  // -A
  const Mat4x4 operator-();

private:
  double mat[4][4];
};

// C = A + B
Mat4x4 operator+(const Mat4x4 &matA, const Mat4x4 &matB);
Mat4x4 operator-(const Mat4x4 &matA, const Mat4x4 &matB);
Mat4x4 operator*(const Mat4x4 &matA, const Mat4x4 &matB);

// 比較
bool operator==(const Mat4x4 &matA, const Mat4x4 &matB);

#endif