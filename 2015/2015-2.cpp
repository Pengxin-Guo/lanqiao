/*************************************************************************
	> File Name: 2015-2.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月22日 星期五 20时31分36秒
 ************************************************************************/

#include <iostream>
using namespace std;

int mm[13] = {0, 31, 28, 31, 30, 
                31, 30, 31, 31,
                30, 31, 30, 31};

int leap_year(int y) {
    return (y % 4 == 0 && y % 100 || y % 400 == 0);
}

int get_next_day(int y, int m, int d) {
    d += 1;
    if (d > (mm[m] + (m == 2 && leap_year(y)))) {
        d = 1;
    }
    return d;
}

int main() {
    int y = 2014, m = 11, d = 9;
    int day = 1000;
    while (day--) {
        d = get_next_day(y, m, d);
        m += (d == 1);
        y += (m == 13 && (m = 1));
    }
    cout << y << "-" << m << "-" << d << endl;
    return 0;
}
