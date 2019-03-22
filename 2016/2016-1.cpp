/*************************************************************************
	> File Name: 2016-1.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月22日 星期五 15时47分57秒
 ************************************************************************/

#include <iostream>
using namespace std;

int is_valid(int x) {
    int y = x - 27;
    int num = 0;
    while (x) {
        num = num * 10 + x % 10;
        x /= 10;
    }
    return num == y;
}

int main() {
    int ans = 0;
    for (int i = 27; i < 100; i++) {
        if (!is_valid(i)) continue;
        ans += 1;
        cout << "i = " << i << ", i - 27 = " << i - 27 << endl;
    }
    cout << ans << endl;
    return 0;
}
