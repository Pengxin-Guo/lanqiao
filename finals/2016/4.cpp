/*************************************************************************
	> File Name: 4.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年05月22日 星期三 16时35分49秒
 ************************************************************************/

#include <iostream>
#include <stack>
using namespace std;
#define MAX_N 20

int vis[MAX_N + 5][MAX_N + 5];
int a[MAX_N + 5], b[MAX_N + 5];  // a代表北,b代表西
int n;
bool flag = false;               // 用来标记是否找到答案
stack<int> ans;                  // 记录最后的答案
stack<int> s;                    // 记录答案的逆序

// 坐标(x, y)在地图内
int in(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

// 向后退一步
void back(int x, int y) {
    a[y] += 1;
    b[x] += 1;
    vis[x][y] = 0;
    if (!s.empty()) s.pop();
    return ;
}

// 用来剪枝
int unvalid(int x, int y) {
    return a[y] < 0 || b[x] < 0;
}

void output() {
    if (s.empty()) return ;
    while (!s.empty()) {
        ans.push(s.top());
        s.pop();
    }
    while (!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }
    cout << endl;
    return ;
}

void dfs(int x, int y) {
    a[y] -= 1;
    b[x] -= 1;
    vis[x][y] = 1;
    s.push(x * n + y);
    if (unvalid(x, y)) {
        back(x, y);
        return ;
    }
    if (x == n - 1 && y == n - 1) {
        for (int i = 0; i < n; i++) {
            if (a[i] != 0 || b[i] != 0) {
                back(x, y);
                return ;
            }
        }
        output();
        return ;
    }
    if (in(x, y + 1) && !vis[x][y + 1]) dfs(x, y + 1);
    if (in(x, y - 1) && !vis[x][y - 1]) dfs(x, y - 1);
    if (in(x + 1, y) && !vis[x + 1][y]) dfs(x + 1, y);
    if (in(x - 1, y) && !vis[x - 1][y]) dfs(x - 1, y);
    back(x, y);
    return ;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    dfs(0, 0);
    return 0;
}
