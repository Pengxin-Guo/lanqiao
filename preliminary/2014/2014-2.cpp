/*************************************************************************
	> File Name: 2014-2.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月23日 星期六 15时31分29秒
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
    int ans = 2;
    for (int i = 1; i <= 10; i++) {
        ans = ans * 2 - 1;
        cout << i << " " << ans << endl;
    }
    return 0;
}
