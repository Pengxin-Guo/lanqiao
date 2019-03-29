/*************************************************************************
	> File Name: 2013-7.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月18日 星期一 21时15分07秒
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 100000

int flag[MAX_N + 5] = {0};

int main() {
    int n, num, m = 0, ind;
    cin >> n;
    while (cin >> num) {
        flag[num] += 1;
    }
    n = 0;
    for (int i = 0; i < MAX_N; i++) {
        if (flag[i] == 0) continue;
        ind = i;
        break;
    }
    for (int i = ind; i < MAX_N; i++) {
        if (flag[i] == 0) m = i;
        else if (flag[i] == 2) n = i;
        if (m && n) break;
    }
    cout << m << " " << n << endl;
    return 0;
}
