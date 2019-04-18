/*************************************************************************
	> File Name: is_prime.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年04月18日 星期四 09时26分57秒
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 10000
int prime[MAX_N + 5] = {0};

// 素数筛
void init() {
    for (int i = 2; i * i <= MAX_N; i++) {
        if (prime[i]) continue;
        for (int j = i * i; j <= MAX_N; j += i) {
            prime[j] = 1;
        }
    }
    return ;
}

int main() {
    init();
    for (int i = 2; i <= MAX_N; i++) {
        if (prime[i]) continue;
        cout << i << endl;
    }
    return 0;
}
