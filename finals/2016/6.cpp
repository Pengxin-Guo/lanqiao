/*************************************************************************
	> File Name: 6.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年05月22日 星期三 21时07分03秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAX_N 100000
#define MOD 1000000007
typedef long long LL;

struct Node {
    int id;       // 小动物的编号
    int pre;      // 左手拉的小动物
    int next;     // 右手拉的小动物
    int h;        // 欢乐值
    int f;        // 感动值
    int t;        // 圈的大小
} node[MAX_N + 5];

int n, m;
int vis[MAX_N + 5];

void init() {
    for (int i = 1; i <= n; i++) {
        node[i].id = i;
        node[i].t = n;
        node[i].next = i + 1;
        node[i].pre = i - 1;
        i == 1 && (node[i].pre = n);
        i == n && (node[i].next = 1);
    }
    return ;
}

// 更新圈的大小
void update() {

}

void change(int p, int q) {
    node[node[p].next].pre = node[q].pre;
    node[node[q].pre].next = node[p].next;
    node[p].next = q;
    node[q].pre = p;
    update();
    return ;
}

// 以动物x为基准产生的能量
LL getSum(int x) {
    int st = node[x].next, cnt = 1;
    LL sum = 0;
    while (node[st].id != x) {
        sum = (sum + (((node[x].t - cnt) % MOD) * (node[st].h % MOD) * (node[st].f % MOD)) % MOD) % MOD;
        st = node[st].next;
        cnt++;
    }
    return sum;
}

void func() {
    LL sum = 0;
    for (int i = 1; i <= n; i++) {
        sum = (sum + getSum(i)) % MOD;
    }
    cout << sum << endl;
}


void output() {
    cout << "队形" << endl;
    for (int i = 1; i <= n; i++) {
        cout << node[i].pre << " " << node[i].id << " " << node[i].next << endl;
    }
    return ;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> node[i].h >> node[i].f;
    }
    init();
    //output();
    cin >> m;
    for (int i = 0; i < m; i++) {
        int k, p, q;
        cin >> k >> p >> q;
        if (k == 1) {
            change(p, q);
            func();
        } else if (k == 2) {
            node[p].h = q;
            func();
        } else if (k == 3) {
            node[p].f = q;
            func();
        }
    }
    return 0;
}
