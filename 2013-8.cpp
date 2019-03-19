/*************************************************************************
	> File Name: 2013-8.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月19日 星期二 09时51分47秒
 ************************************************************************/

#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// x是否可以由n和m组成出来
int func(int x, int n, int m) {
    int ind1 = x / n + 1, ind2 = x / m + 1;
    for (int i = 0; i <= ind1; i++) {
        for (int j = 0; j <= ind2; j++) {
            if (i * n + j * m == x) return 1;
        }
    }
    return 0;
}

int main() {
    int n, m, x, y, ans;
    cin >> n >> m;
    if (n < m) {
        n ^= m, m ^= n, n ^= m;
    }
    x = gcd(n, m);
    y = n * m / x;
    for (int i = y; i >= 0; i--) {
        if (func(i, n, m)) continue;
        ans = i;
        break;
    }
    cout << ans << endl;
    return 0;
}
