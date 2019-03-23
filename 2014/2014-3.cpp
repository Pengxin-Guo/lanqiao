/*************************************************************************
	> File Name: 2014-3.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月23日 星期六 15时37分56秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int vis[10] = {0};

int is_valid(int x, int y) {
    int num = x * y;
    int cnt = 0;
    while (x) {
        if (vis[x % 10]) return 0;
        vis[x % 10] = 1;
        x /= 10;
        cnt += 1;
    }
    while (y) {
        if (vis[y % 10]) return 0;
        vis[y % 10] = 1;
        y /= 10;
        cnt += 1;
    }
    if (cnt != 4) return 0;
    cnt = 0;
    while (num) {
        if (vis[num % 10] == 0) return 0;
        vis[num % 10] = 0;
        num /= 10;
        cnt += 1;
    }
    return cnt == 4;
}

int main() {
    int ans = 0;
    for (int i = 1; i < 40; i++) {
        for (int j = 1; j < 9999; j++) {
            memset(vis, 0, sizeof(vis));
            if (is_valid(i, j)) {
                cout << i << " * " << j << " = " << i * j << endl;
                ans += 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
