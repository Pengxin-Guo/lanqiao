/*************************************************************************
	> File Name: 2015-6.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月23日 星期六 09时36分59秒
 ************************************************************************/

#include <iostream>
using namespace std;

int a[13] = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4};
int ans = 0;

void dfs(int num, int cnt) {
    if (cnt == 13) {
        ans += 1;
        return ;
    }
    for (int i = num; i < 13; i++) {
        if (a[i] != 0) {
            a[i] -= 1;
            dfs(i, cnt + 1);
            a[i] += 1;
        }
    }
    return ;
}

int main() {
    dfs(0, 0);
    cout << ans << endl;
    return 0;
}
