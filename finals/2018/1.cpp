/*************************************************************************
	> File Name: 1.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年05月02日 星期四 09时28分59秒
 ************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;
// A(2.3, 2.5), B(6.4, 3.1), C(5.1, 7.2)
// 求A,B,C三点围成的三角形的面积
// 设直线AC所在的方程为y = a * x + b;
double a, b;

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void get_ab(double x1, double y1, double x2, double y2) {
    a = (y2 - y1) / (x2 - x1);
    b = y1 - x1 * a;
    //cout << a << " " << b << endl;
    return ;
}

// (x, y)到直线y = a * x + b的距离
double func(double x, double y) {
    return abs(a * x - y + b) / sqrt(a * a + 1);
}

// 法二：直接通过公式求
double f(double x1, double y1, double x2, double y2, double x3, double y3) {
    return (x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2) / 2;
}

int main() {
    double DAC = dist(2.3, 2.5, 5.1, 7.2);
    get_ab(2.3, 2.5, 5.1, 7.2);
    double DBAC = func(6.4, 3.1);
    cout << DAC * DBAC / 2 << endl;
    cout << f(2.3, 2.5, 6.4, 3.1, 5.1, 7.2) << endl;
    return 0;
}
