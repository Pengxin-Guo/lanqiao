/*************************************************************************
	> File Name: topo.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年04月09日 星期二 10时19分56秒
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;
#define MAX_N 100

struct Edge {
    int to, next;
} g[MAX_N + 5];
int head[MAX_N + 5], cnt = 0;
int n, m;
int degree[MAX_N + 5];

inline void add(int a, int b) {
    g[++cnt].to = b;
    g[cnt].next = head[a];
    head[a] = cnt;
}

bool topo() {
    int num = 0;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (degree[i]) continue;
        q.push(i);
        num++;
    }
    while (!q.empty()) {
        int ind = q.front();
        q.pop();
        for (int j = head[ind]; j; j = g[j].next) {
            int to = g[j].to;
            degree[to]--;
            if (degree[to] == 0) {
            	q.push(to);
                num++;
            }
        }
    }
    return num == n;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        add(x, y);
        degree[y]++;
    }
    if (topo()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
