/*************************************************************************
	> File Name: BIT.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年04月26日 星期五 18时57分39秒
 ************************************************************************/
// 树状数组
/*
 树状数组中结点i表示的区间为[i - lowbit(i) + 1, i]
 数组c表示每个结点对应的区间内的和
*/

#include <iostream>
using namespace std;
#define MAX_N 100

int n, c[MAX_N + 5];

// lowbit(x)为x的二进制表示中最右边１所对应的值
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
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int v;
        cin >> v;
        update(i, v);
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << getsum(r) - getsum(l - 1) << endl;
    }
    return 0;
}
