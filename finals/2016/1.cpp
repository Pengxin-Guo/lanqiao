/*************************************************************************
	> File Name: 1.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年05月22日 星期三 15时26分01秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a1[4] = {2, 3, 5, 8}, a2[4] = {1, 4, 6, 7};

int main() {
    int cnt = 0;
    do {
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < 4; i++) {
            sum1 += (a1[i] * 10 + a2[i]) * (a1[i] * 10 + a2[i]);
            sum2 += (a1[i] + a2[i] * 10) * (a1[i] + a2[i] * 10);
            cnt += (sum1 == sum2);
            if (sum1 == sum2) {
                printf("{(%d, %d), (%d, %d), (%d, %d), (%d, %d)}\n", a1[0], a2[0], a1[1], a2[1], a1[2], a2[2], a1[3], a2[3]);
            }
        }
    } while (next_permutation(a2, a2 + 4));
    cout << cnt << endl;
    return 0;
}
