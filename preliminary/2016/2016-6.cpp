/*************************************************************************
	> File Name: 2016-6.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月22日 星期五 16时54分19秒
 ************************************************************************/

#include <iostream>
using namespace std;

int vis[15] = {0};
int ans = 0;

void dfs(int num1, int num2, int num3, int cnt) {
    if (cnt == 3) {
        if (num1 +  num2 != num3) return ;
    }
    if (cnt == 6) {
        if (num1 - num2 != num3) return ;
    }
    if (cnt == 9) {
        if (num1 * num2 != num3) return ;
    }
    if (cnt == 12) {
        // 必须整除, 变成乘法判断
        // 第一次出错就是这儿错了！！！
        if (num2 * num3 == num1) {
            ans++;
        }
        return ;
    }
    for (int i = 1; i <= 13; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            dfs(num2, num3, i, cnt + 1);
            vis[i] = 0;
        }
    }
    return ;
}

int main() {
    dfs(0, 0, 0, 0);
    cout << ans << endl;
    return 0;
}
