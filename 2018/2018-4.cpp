/*************************************************************************
	> File Name: 2018-4.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月19日 星期二 20时38分18秒
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 59084709587505

int valid(long long x) {
    if (x % 3 && x % 5 && x % 7) return 0;
    while (x % 105 == 0) {
        x /= 105;
    }
    while (x % 35 == 0) {
        x /= 35;
    }
    while (x % 21 == 0) {
        x /= 21;
    }
    while (x % 15 == 0) {
        x /= 15;
    }
    while (x % 7 == 0) {
        x /= 7;
    }
    while (x % 5 == 0) {
        x /= 5;
    }
    while (x % 3 == 0) {
        x /= 3;
    }
    return (x == 1);
}

int main() {
    int ans = 0;
    for (long long i = 3; i <= MAX_N; i++) {
        if (!valid(i)) continue;
        ans++;
        cout << " num = " << i << " cnt = " << ans << endl;
    }
    cout << ans << endl;
    return 0;
}
