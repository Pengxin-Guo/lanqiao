/*************************************************************************
	> File Name: 2014-7.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月23日 星期六 16时21分06秒
 ************************************************************************/
// 这么简单的题, 调bug调了一下午......
/* 这道题还是比较有意思的，首先有一点，两只蚂蚁相遇之后，虽然说是各自掉头，但是如果有一直感冒了，那么另一只一会感冒，那么掉头不掉头都是一样的，因为结果一样，都是两只感冒的蚂蚁背向而行，所以我们可以推出来，第一只蚂蚁左边向右走的，右边向左走的都会感冒，这里也有特殊的情况，如果第一只感冒的蚂蚁左边没有向右走的，右边没有向左走的最后的感染数是1，模拟一下就知道了，所以现在的目标就是计算出左，右，然后加1，这就是最后的感染数

*/

#include <iostream>
using namespace std;

int main() {
    int n, id, ans = 1, data[105] = {0};
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num = 0;
        cin >> num;
        if (num < 0) {
            num = -num;
            data[num] = -1;
        } else {
            data[num] = 1;
        }
        if (i == 0) id = num;
    }
    if (data[id] > 0) {
        for (int i = id + 1; i < 105; i++) {
            if (data[i] == -1) ans += 1;
        }
        if (ans > 1) {
            for (int i = 0; i < id; i++) {
                if (data[i] == 1) ans += 1;
            }
        }
    } else {
        for (int i = id - 1; i >= 0; i--) {
            if (data[i] == 1) ans += 1;
        }
        if (ans > 0) {
            for (int i = id + 1; i < 105; i++) {
                if (data[i] == -1) ans += 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
