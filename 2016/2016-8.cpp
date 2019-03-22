/*************************************************************************
	> File Name: 2016-8.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月22日 星期五 18时43分43秒
 ************************************************************************/

#include <iostream>
using namespace std;

int n;

int is_valid(int i, int j, int k, int l) {
    if (i * i + j * j + k * k + l * l == n) {
        cout << i << " " << j << " " << k << " " << l << endl;
        return 1;
    }
    return 0;
}

int main() {
    cin >> n;
    for (int i = 0; i * i * 4 <= n; i++) {
        for (int j = i; j * j * 3 <= n; j++) {
            for (int k = j; k * k * 2 <= n; k++) {
                for (int l = k; l * l <= n; l++) {
                    if (is_valid(i, j, k, l)) return 0;
                }
            }
        }
    }
    return 0;
}
