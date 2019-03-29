/*************************************************************************
	> File Name: 2018-2.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月19日 星期二 20时17分20秒
 ************************************************************************/
// 1901年1月1日至2000年12月31日 一共有多少个星期一
// 2000年12月31日是周日

#include <iostream>
using namespace std;

int leap_year(int y) {
    return (y % 4 == 0 && y % 100 != 0 || y % 400 == 0);
}

int main() {
    int leap_num = 0;
    for (int i = 1901; i <= 2000; i++) {
        if (leap_year(i)) leap_num++;
    }
    int days = 365 * 100 + leap_num;
    int ans1 = days / 7;
    int temp = days % 7;
    cout << "ans1 = " << ans1 << " temp =  " << temp << endl;
    // 由于temp = 6, 即整除完星期后还多6天, 又由2000年12月31日是周日, 所以多出的6天里面没有周一
    // 所以 ans = ans1
    return 0;
}
