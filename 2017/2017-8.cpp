/*************************************************************************
	> File Name: 2017-8.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月21日 星期四 20时57分13秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 100000

int n, k, ans = 0;
int arr[MAX_N + 5][2];

// h * w 的巧克力可以分成几块 a * a 的
int func(int a, int h, int w) {
    int c = 0;
    int ww = w;
    while (h >= a) {
        while (w >= a) {
            c++;
            w -= a;
        }
        h -= a;
        w = ww;
    }
    return c;
}

// 按照边长为num来分是否符合要求
int is_valid(int num) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += func(num, arr[i][0], arr[i][1]);
    }
    return (cnt >= k);
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
        ans = max(ans, arr[i][0]);
        ans = max(ans, arr[i][1]);
    }
    int head = 0, tail = ans, mid;
    // 11110000求最后一个1的位置
    while (head < tail) {
        mid = ((head + tail) >> 1) + 1;
        if (!is_valid(mid)) tail = mid - 1;
        else head = mid;
    }
    cout << tail << endl;
    return 0;
}
