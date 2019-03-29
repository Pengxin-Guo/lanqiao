/*************************************************************************
	> File Name: 2017-1.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月20日 星期三 10时38分20秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char mat[15][15];
int vis[15][15];
bool f;

void dfs(int i, int j) {
    if (vis[i][j]) return ;
    if (f) return ;
    if (i < 1 || j < 1 || i > 10 || j > 10) {
        f = true;
        return ;
    }
    vis[i][j] = 1;
    if (mat[i][j] == 'U') {
        dfs(i - 1, j);
    } else if (mat[i][j] == 'D') {
        dfs(i + 1, j);
    } else if (mat[i][j] == 'L') {
        dfs(i, j - 1);
    } else if (mat[i][j] == 'R') {
        dfs(i, j + 1);
    }
}

int main() {
    int ans = 0;
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            cin >> mat[i][j];
        }
    }
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            f = false;
            memset(vis, 0, sizeof(vis));
            dfs(i, j);
            if (f) ans += 1;
        }
    }
    cout << ans << endl;
    return 0;
}
