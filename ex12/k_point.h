#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;


  struct Point {
   Point() : x(0.0), y(0.0), z(0.0) {}
   Point(double x, double y, double z) : x(x), y(y), z(z) {}
   double x, y, z;
  };

  class Compare{
      public:
      //Compare(const Point& a, const Point& b) : a(a), b(b){}
      

      bool operator()(const Point& a, const Point& b){ 
        auto a_sqrt = sqrt(pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2));
        auto b_sqrt = sqrt(pow(b.x, 2) + pow(b.y, 2) + pow(b.z, 2));
        return a_sqrt > b_sqrt;   //true or false
        }

      private:
      Point a, b;   
    };

  vector<Point> find_k_closest(int k, vector<Point> Points)
{


  priority_queue<double, vector<Point>, decltype(Compare())> que{Compare()};

    for(int i=Points.size()-1; i>=0; --i){
      que.push(Points[i]);

    }


    vector<Point> list;
    
    for(int i = 0; i<k; i++){
        list.push_back(que.top());
        que.pop();

    }

    return list;

}
#endif