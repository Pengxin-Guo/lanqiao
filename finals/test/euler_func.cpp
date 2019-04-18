/*************************************************************************
	> File Name: euler_func.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年04月18日 星期四 10时17分51秒
 ************************************************************************/
/*
 * 欧拉函数f(x):小于等于n的所有数中与n互质的数的个数
 * f(x) = x * (1 - 1 / p1) * (1 - 1 / p2) * ... * (1 - 1 / pn), 其中p1, p2, ... pn是x的所有质因数 
 */

#include <iostream>
using namespace std;
#define MAX_N 100

// 计算一个数的欧拉函数
int euler_func(int x) {
    int res = x;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            res = res / i * (i - 1);
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x > 1) {
        res = res / x * (x - 1);
    }
    return res;
}

int phi[MAX_N + 5];
// 区间预处理欧拉函数
void init() {
    for (int i = 1; i <= MAX_N; i++) {
        phi[i] = i;
    }
    for (int i = 2; i <= MAX_N; i++) {
        if (phi[i] != i) continue;
        for (int j = i; j <= MAX_N; j += i) {
            phi[j] = phi[j] / i * (i - 1);
        }
    }
    return ;
}


int main() {
    init();
    for (int i = 1; i <= MAX_N; i++) {
        cout << "phi(" << i << ") = " << phi[i] << endl;
    }
    return 0;
}
