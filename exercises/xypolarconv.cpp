#include <iostream>
#include <cmath>
using namespace std;

void xy2polar(double x, double y, double& r, double& t) {
r = hypot(x,y);
t = atan2(x,y);
}

void polar2xy(double r, double t, double& x, double &y) {
x = r*cos(t);
y = r*sin(t);
}

int main() {
     double x,y,r,t;

     cout << "Enter x-coordinate --> " ; cin >> x;
     cout << "Enter y-coordinate --> " ; cin >> y;
     xy2polar(x,y,r,t);
     cout << "The point (" << x << "," << y
          << ") in polar coordinates is ("
          << r << "," << t << ")" << endl;

     cout << "Enter radius --> " ; cin >> r;
     cout << "Enter theta --> " ; cin >> t;
     polar2xy(r,t,x,y);
     cout << "The point in polar coordinates (" << r
          << "," << t << ") is (" << x << "," << y << ")" << endl;

     return 0;
}
