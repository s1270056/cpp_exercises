#include <iostream>
#include <vector>

#include "k_2point.h"
using namespace std;

int main(void) {
    int j = 1;
 vector<Point> points;

 points.push_back(Point(1.0,2.0,3.0));
 points.push_back(Point(1.0,1.0,1.0));
 points.push_back(Point(4.0,2.0,1.0));
 points.push_back(Point(9.0,2.0,1.0));
 points.push_back(Point(1.0,2.0,1.0));
 points.push_back(Point(0.0,0.0,1.0));
 points.push_back(Point(5.0,0.0,0.0));
 points.push_back(Point(2.0,2.0,1.0));

 cout << "find_k_closest" << endl;
 
 vector<Point> list = find_k_closest(4, points);

 for (int i = 0; i < 4; ++i) {
   std::cout << j << "番目に近い: " << list[i].x << ", " << list[i].y << ", " << list[i].z << std::endl;
   j++;
 }

 cout << "find_k_closest_2" << endl;

  vector<Point> list2 = find_k_closest_2(4, points);
    j=1;

 for (int i = 0; i < 4; ++i) {
   std::cout << j << "番目に近い: " << list2[i].x << ", " << list2[i].y << ", " << list2[i].z << std::endl;
   j++;
 }

 return 0;
}
