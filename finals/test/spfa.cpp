/*************************************************************************
	> File Name: spfa.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年04月05日 星期五 10时27分56秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define MAX_M 500000
#define MAX_N 10000
#define INF 0x3f3f3f3f

struct Edge {
    int to, next, c;
} g[MAX_M + 5];
int head[MAX_N + 5], cnt = 0;
int dis[MAX_N + 5], vis[MAX_N + 5];

inline void add(int a, int b, int c) {
    g[++cnt].to = b;
    g[cnt].c = c;
    g[cnt].next = head[a];
    head[a] = cnt;
}

void spfa(int s) {
    queue<int> q;
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    vis[s] = 1;
    q.push(s);
    while (!q.empty()) {
        int ind = q.front();
        q.pop();
        vis[ind] = 0;
        for (int i = head[ind]; i; i = g[i].next) {
            int to = g[i].to, c = g[i].c;
            if (dis[to] <= dis[ind] + c) continue;
            dis[to] = dis[ind] + c;
            if (vis[to] == 0) {
                q.push(to);
                vis[to] = 1;
            }
        }
    }
    return ;
}

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    spfa(s);
    for (int i = 1; i <= n; i++) {
        i == 1 || cout << " ";
        if (dis[i] == INF) {
            cout << "2147483647";
        } else {
            cout << dis[i];
        }
    }
    cout << endl;
    return 0;
}
