/*************************************************************************
	> File Name: 2015-3.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月22日 星期五 20时40分32秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int use[10] = {0};

int is_valid(int i) {
    int x = i * i, y = i * i * i;
    int cnt = 0;
    while (x) {
        if (use[x % 10]) return 0;
        use[x % 10] = 1;
        x /= 10;
        cnt++;
    }
    while (y) {
        if (use[y % 10]) return 0;
        use[y % 10] = 1;
        y /= 10;
        cnt++;
    }
    return cnt == 10;
}

int main() {
    for (int i = 10; i < 100; i++) {
        memset(use, 0, sizeof(use));
        if (is_valid(i)) {
            cout << "i = " << i << " i * i = " << i * i << " i * i * i = " << i * i * i << endl;
            break;
        }
    }
    return 0;
}
