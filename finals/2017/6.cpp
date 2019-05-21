/*************************************************************************
	> File Name: 6.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年05月21日 星期二 20时31分19秒
 ************************************************************************/

// 本地测评正确,提交提示内存超限
#include <iostream>
using namespace std;
#define MAX_N 10000

int n, m, c[MAX_N + 5], a[MAX_N + 5], tmp[MAX_N + 5];

int lowbit(int x) {
    return x & (-x);
}

int getsum(int x) {
    int sum = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
        sum += c[i];
    }
    return sum;
}

void update(int x, int v) {
    for (int i = x; i <= n; i += lowbit(i)) {
        c[i] += v;
    }
    return ;
}

int main() {
    int v;
    cin >> v;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> v;
        a[i] = v;
        update(i, v);
    }
    for (int i = 0; i < m; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r, d;
            cin >> l >> r >> d;
            for (int j = l; j <= r; j++) {
                update(j, d);
                a[j] += d;
            }
        } else if (op == 2) {
            int l1, r1, l2, r2;
            cin >> l1 >> r1 >> l2 >> r2;
            for (int j = 0; j <= r2 - l2; j++) {
                tmp[j] = a[l2 + j];
                update(l1 + j, a[l2 + j] - a[l1 + j]);
            }
            for (int j = 0; j <= r1 - l1; j++) {
                a[l1 + j] = tmp[j];
            }
        } else if (op == 3) {
            int l, r;
            cin >> l >> r;
            cout << getsum(r) - getsum(l - 1) << endl;
        }
    }
    return 0;
}
