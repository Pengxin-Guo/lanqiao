/*************************************************************************
	> File Name: 6.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年05月21日 星期二 20时31分19秒
 ************************************************************************/

// TLE代码
#include <iostream>
using namespace std;
#define MAX_N 100000
typedef long long LL;

LL n, m, a[MAX_N + 5], d[MAX_N + 5], tmp[MAX_N + 5];
// d[n] = d[n] - d[n - 1]

void update() {
    for (int i = 1; i <= n; i++) {
        d[i] = a[i] - a[i - 1];
    }
    return ;
}

void getA() {
    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + d[i];
    }
}

int main() {
    int v;
    cin >> v;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> v;
        a[i] = v;
    }
    update();
    for (int i = 0; i < m; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            d[l] += + x;
            d[r + 1] -= x;
        } else if (op == 2) {
            int l1, r1, l2, r2;
            cin >> l1 >> r1 >> l2 >> r2;
            getA();
            for (int j = 0; j <= r2 - l2; j++) {
                tmp[j] = a[l2 + j];
            }
            for (int j = 0; j <= r1 - l1; j++) {
                a[l1 + j] = tmp[j];
            }
            update();
        } else if (op == 3) {
            int l, r;
            cin >> l >> r;
            getA();
            LL sum = 0;
            for (int j = l; j <= r; j++) {
                sum += a[j];
            }
            cout << sum << endl;
        }
    }
    return 0;
}
