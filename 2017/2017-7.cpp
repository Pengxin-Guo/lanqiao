/*************************************************************************
	> File Name: 2017-7.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月21日 星期四 20时31分21秒
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

int len;
char s[105];
int p = 0;

int dfs() {
    int ans = 0;      // 代表当前连续x的字符长度
    int result = 0;   // 代表当前答案
    while (p < len) {
        if (s[p] == '(') {
            p++;
            ans = ans + dfs();
        } else if (s[p] == ')') {
            p++;
            break;
        } else if (s[p] == '|') {
            p++;
            result = max(ans, result);
            ans = 0;
        } else {
            p++;
            ans++;
        }
    }
    result = max(result, ans);
    return result;
}

int main() {
    cin >> s;
    len = strlen(s);
    cout << dfs() << endl;
    return 0;
}
