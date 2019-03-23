/*************************************************************************
	> File Name: 2015-8.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月23日 星期六 10时05分41秒
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
    int n, ans;
    cin >> n;
    ans = n;
    while (n >= 3) {
        n -= 3;
        ans += 1;
        n += 1;
    }
    cout << ans << endl;
    return 0;
}
