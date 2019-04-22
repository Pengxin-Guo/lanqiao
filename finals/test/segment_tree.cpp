/*************************************************************************
	> File Name: segment_tree.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年04月22日 星期一 10时36分08秒
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 10000
const int INF = 0x3f3f3f3f;
int a[MAX_N + 5];
int minv[4 * MAX_N + 5];

void pushup(int id) {
    minv[id] = min(minv[id << 1], minv[id << 1 | 1]);
    return ;
}

void build(int id, int l, int r) {
    if (l == r) {
        minv[id] = a[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    pushup(id);
    return ;
}

// 更新过程只更新了minv数组, 不再管a数组了
void update(int id, int l, int r, int x, int v) {
    if (l == r) {
        minv[id] = v;
        return ;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) {
        update(id << 1, l, mid, x, v);
    } else {
        update(id << 1 | 1, mid + 1, r, x, v);
    }
    pushup(id);
    return ;
}

int query(int id, int l, int r, int x, int y) {
    if (x <= l && y >= r) {
        return minv[id];
    }
    int mid = (l + r) >> 1;
    int ans = INF;
    if (x <= mid) {
        ans = min(ans, query(id << 1, l, mid, x, y));
    }
    if (y > mid) {
        ans = min(ans, query(id << 1 | 1, mid + 1, r, x, y));
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    int op;
    cin >> op;
    while (op--) {
        int a, b, c;
        cin >> a >> b >> c;
        switch (a) {
            case 1: {
                cout << "update segment_tree" << endl;
                update(1, 1, n, b, c);
            } break;
            case 2: {
                cout << "query segment_tree: ";
                printf("[%d, %d] 的最小值为: %d\n", b, c, query(1, 1, n, b, c));
            } break;
        }
    }
    return 0;
}
