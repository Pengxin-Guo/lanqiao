/*************************************************************************
	> File Name: 2013-2.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月18日 星期一 10时53分03秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int vis[10];

int is_valid(long long x) {
    while (x) {
        if (vis[x % 10]) return 0;
        vis[x % 10] = 1;
        x /= 10;
    }
    return 1;
}

int is_ans(long long ans) {
    while (ans) {
        if (vis[ans % 10]) return 0;
        ans /= 10;
    }
    return 1;
}

int main() {
    for (long long i = 100000; i < 999999; i++) {
        memset(vis, 0, sizeof(vis));
        if (!is_valid(i)) continue;
        long long ans = i * i;
        if (!is_ans(ans)) continue;
        cout << i << endl;
    }
    return 0;
}
