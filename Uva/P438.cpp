#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const double eps = 1e-6;
const double PI = 3.141592653589793;
struct Point
{
    double x, y;
    Point operator-(Point &it)
    {
        Point tmp;
        tmp.x = x - it.x;
        tmp.y = y - it.y;
        return tmp;
    }
};
struct Circle
{
    double radis;
    Point center;
};
struct Triangle
{
    Point t[3];
};

double dist(Point a, Point b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double triangleArea(Triangle t)
{
    Point p1, p2;
    p1 = t.t[1] - t.t[0];
    p2 = t.t[2] - t.t[0];
    return fabs(p1.x * p2.y - p1.y * p2.x) / 2;
}
Circle circumcircleOfTriangle(Triangle t)
{
    //¿?¿?¿?¿?¿?¿?¿?
    Circle tmp;
    double a, b, c, c1, c2;
    double xA, yA, xB, yB, xC, yC;
    a = dist(t.t[0], t.t[1]);
    b = dist(t.t[1], t.t[2]);
    c = dist(t.t[2], t.t[0]);
    //¿?¿?S = a * b * c / R / 4;¿?¿?¿?R 
    tmp.radis = a * b * c / triangleArea(t) / 4;

    xA = t.t[0].x, yA = t.t[0].y;
    xB = t.t[1].x, yB = t.t[1].y;
    xC = t.t[2].x, yC = t.t[2].y;
    c1 = (xA * xA + yA * yA - xB * xB - yB * yB) / 2;
    c2 = (xA * xA + yA * yA - xC * xC - yC * yC) / 2;

    tmp.center.x = (c1 * (yA - yC) - c2 * (yA - yB)) / ((xA - xB) * (yA - yC) - (xA - xC) * (yA - yB));
    tmp.center.y = (c1 * (xA - xC) - c2 * (xA - xB)) / ((yA - yB) * (xA - xC) - (yA - yC) * (xA - xB));
    return tmp;
}
Circle c;
Point a[5];
int main()
{
	freopen("a", "r", stdin);
	Triangle t;
	while (scanf("%lf%lf%lf%lf%lf%lf", &t.t[0].x, &t.t[0].y, &t.t[1].x, &t.t[1].y, &t.t[2].x, &t.t[2].y) != EOF)
	{
		c = circumcircleOfTriangle(t);
		double ans = 2 * PI * c.radis;
		printf("%.2lf\n", ans);
	}
	return 0;
}


