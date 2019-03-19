/*************************************************************************
	> File Name: 2018-3.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月19日 星期二 20时25分27秒
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 1000

int ans[MAX_N + 5] = {1, 1};

int main() {
    for (int i = 1; i <= 100; i++) {
        int num;
        cin >> num;
        for (int i = 1; i <= ans[0]; i++) {
            ans[i] *= num;
        }
        for (int i = 1; i <= ans[0]; i++) {
            if (ans[i] < 10) continue;
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
            ans[0] += (i == ans[0]);
        }
    }
    for (int i = ans[0]; i >= 1; i--) {
        cout << ans[i];
    }
    cout << endl;
    int cnt = 0;
    for (int i = 1; i <= ans[0]; i++) {
        if (ans[i]) break;
        cnt += 1;
    }
    cout << cnt << endl;
    return 0;
}
