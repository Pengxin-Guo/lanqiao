/*************************************************************************
	> File Name: 2013-9.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月19日 星期二 10时15分03秒
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 10

int arr[MAX_N + 5][MAX_N + 5];
int n, m, sum = 0, ans = 100;
int vis[MAX_N + 5][MAX_N + 5] = {0};

void dfs(int i, int j, int num, int cnt) {
    if (num > sum) return;
    if (num == sum) {
        ans = min(ans, cnt);
        return ;
    }
    vis[i][j] = 1;
    if (i < n && !vis[i + 1][j]) dfs(i + 1, j, num + arr[i][j], cnt + 1);
    if (i > 1 && !vis[i - 1][j]) dfs(i - 1, j, num + arr[i][j], cnt + 1);
    if (j < m && !vis[i][j + 1]) dfs(i, j + 1, num + arr[i][j], cnt + 1);
    if (j > 1 && !vis[i][j - 1]) dfs(i, j - 1, num + arr[i][j], cnt + 1);
    vis[i][j] = 0;
}

int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
            sum += arr[i][j];
        }
    }
    if (sum & 1) {
        cout << 0 << endl;
    } else {
        sum >>= 1;
        dfs(1, 1, 0, 0);
        if (ans == 100) cout << 0 << endl;
        else cout << ans << endl;
    }
    return 0;
}
