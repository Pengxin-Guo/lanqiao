/*************************************************************************
	> File Name: 4.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年05月02日 星期四 10时47分12秒
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;
#define MAX_N 1000000
int n, k;

int func() {
    queue<int> q;
    int num = 1;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    while (q.size() > 1) {
        int tmp = q.front();
        q.pop();
        if (num != k) {
            q.push(tmp);
            num++;
        }
        else num = 1;
    }
    return q.front();
}

int main() {
    cin >> n >> k;
    cout << func() << endl;
    return 0;
}
