/*************************************************************************
	> File Name: 2.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年05月02日 星期四 09时56分24秒
 ************************************************************************/

#include <iostream>
#include <map>
using namespace std;
#define MAX_OP 2000
typedef long long LL;

// 利用map来统计每种人数可以组成的队形数
map<LL, int> m;


int main() {
    int flag = 1;
    LL ans = 0;
    for (int i = 1; i <= MAX_OP && flag; i++) {
        for (int j = i; j <= MAX_OP && flag; j++) {
            LL num = i * i + j * j;
            ++m[num];
            if (m[num] == 12) {
                flag = 0;
                ans = num;
            }
            if (num == 160225) {
                cout << "i = " << i << " j = " << j << endl;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
