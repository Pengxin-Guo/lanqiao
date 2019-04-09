/*************************************************************************
	> File Name: floyd.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月31日 星期日 20时55分51秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAX_N 100
#define INF 0x3f3f3f3f
int dp[MAX_N + 5][MAX_N + 5] = {0};


int main() {
    memset(dp, 0x3f, sizeof(dp));
    int n, m, s;
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dp[a][b] = min(c, dp[a][b]);
    }
    for (int i = 1; i <= n; i++) dp[i][i] = 0;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        i == 1 || cout << " ";
        if (dp[s][i] == INF) {
            cout << "2147483647";
        } else {
            cout << dp[s][i];
        }
    }
    cout << endl;
    return 0;
}


