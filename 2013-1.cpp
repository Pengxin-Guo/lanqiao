/*************************************************************************
	> File Name: 2013-1.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月18日 星期一 10时17分48秒
 ************************************************************************/

#include <iostream>
using namespace std;

int mon[13] = {0, 31, 28, 31, 30,
                31, 30, 31, 31,
                30, 31, 30, 31};

int leap_year(int y) {
    return (y % 4 == 0 && y % 100 != 0 || y % 400 == 0);
}

int get_next_day(int y, int m, int d) {
    d += 1;
    if (d > (mon[m] + (m == 2 && leap_year(y)))) {
        d = 1;
    }
    return d;
}

int main() {
    int y = 1777, m = 4, d = 30;
    int days = 8113;
    days -= 1;
    while (days--) {
        d = get_next_day(y, m, d);
        m += (d == 1);
        y += (m == 13 && (m = 1));
    }
    cout << y << "-" << m << "-" << d << endl;
    return 0;
}
