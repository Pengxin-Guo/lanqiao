/*************************************************************************
	> File Name: 2013-10.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月19日 星期二 15时54分02秒
 ************************************************************************/
// 树的直径问题

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define MAX_N 10000
const int INF = 0x3f3f3f;

int n, st, len = 0;
int vis[MAX_N + 5] = {0};

struct node {
    node(int vv, int ww) : v(vv), w(ww) {}
    int v, w;            // v代表这条边的终点, w代表这条边的权重
};

vector<node> vt[MAX_N + 5];

void dfs(int x, int cur) {
    if (cur > len) {
        st = x;          // 第二次dfs的起始位置
        len = cur;
    }
    for (int i = 0; i < vt[x].size(); i++) {
        int y = vt[x][i].v;
        int d = vt[x][i].w;
        if (!vis[y]) {
            vis[y] = 1;
            dfs(y, cur + d);
            vis[y] = 0;
        }
    }
}

int get_ans(int len) {
    return (11 + 10 + len) * len / 2;
}

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        node n1(b, c);
        node n2(a, c);
        vt[a].push_back(n1);
        vt[b].push_back(n2);
    }
    vis[1] = 1;
    dfs(1, 0);
    memset(vis, 0, sizeof(vis));
    len = 0;
    vis[st] = 1;
    dfs(st, 0);
    cout << get_ans(len) << endl;
    return 0;
}
