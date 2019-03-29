/*************************************************************************
	> File Name: 2017-9.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月22日 星期五 09时19分52秒
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 10000

int arr[105];
int n;
int dp[MAX_N + 5];

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int g, mmin = 100;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mmin = min(mmin, arr[i]);
        if (i == 0) g = arr[0];
        else g = gcd(g, arr[i]);
    }
    if (g == 1) {
        dp[0] = 1;                                          // 0个包子一定是能凑出来的
        for (int i = 0; i < n; i++) {
            for (int j = 0; j + arr[i] < MAX_N; j++) {
                if (dp[j]) dp[j + arr[i]] = 1;              // 把所有能凑出来的标记一下
            }
        }
        int cnt = 0;
        for (int i = 0; i < MAX_N; i++) {
            if (dp[i]) continue;
            cnt += 1;
        }
        cout << cnt << endl;
    } else {
        cout << "INF" << endl;
    }
    return 0;
}
