/*************************************************************************
	> File Name: 6.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年05月22日 星期三 21时07分03秒
 ************************************************************************/

#include <iostream>
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
} node[MAX_N + 5];

int n, m;

void change(int p, int q) {

}

void output() {

}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> node[i].h >> node[i].f;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int k, p, q;
        cin >> k >> p >> q;
        if (k == 1) {
            change(p, q);
            output();
        } else if (k == 2) {
            node[p].h = q;
            output();
        } else if (k == 3) {
            node[p].f = q;
            output();
        }
    }
    return 0;
}
