/*************************************************************************
	> File Name: 2015-10.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月23日 星期六 10时36分32秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX_N 1000000
int n, m, q;

struct UnionSet {
    UnionSet (int n) {
        this->n = n;
        for (int i = 1; i <= n; i++) {
            this->father[i] = i;
            this->size[i] = 1;
        }
    }
    int find(int x) {
        if (x != father[x])
            return (father[x] = find(father[x]));
        return x;
    }
    int merge(int a, int b) {
        int fa = find(a), fb = find(b);
        if (fa == fb) return 1;
        if (fa < fb) {
            fa ^= fb, fb ^= fa, fa ^= fb;
        }
        father[fb] = fa;
        size[fa] += size[fb];
        return 1;
    }
    int n;
    int father[MAX_N];
    int size[MAX_N];
};

struct Edge {
    int u, v, w;
} edge[MAX_N];

int cmp(Edge e1, Edge e2) {
    return e1.w < e2.w;
}

int is_valid(UnionSet &u, vector<int> &v) {
    for (int i = 0; i < v.size() - 1; i++) {
        if (u.find(v[i]) != u.find(v[i + 1])) return 0;
    }
    return 1;
}

void func(UnionSet &u, vector<int> &v) {
    for (int i = 0; i < m; i++) {
        u.merge(edge[i].u, edge[i].v);
        if (is_valid(u, v)) {
            cout << edge[i].w << endl;
            break;
        }
    }
    return ;
}

int main() {
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    }
    sort(edge, edge + m, cmp);
    for (int i = 0; i < q; i++) {
        int l, r, k, c;
        vector<int> v;
        UnionSet u(n);
        cin >> l >> r >> k >> c;
        for (int j = l; j <= r; j++) {
            if (j % k == c) v.push_back(j);
        }
        func(u, v);
    }
    return 0;
}
