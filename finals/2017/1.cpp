/*************************************************************************
	> File Name: 1.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年05月02日 星期四 16时03分08秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

bool is_valid(int *num) {
    long long sum = 0;
    for (int i = 0; i < 10; i++) {
        sum = sum * 10 + num[i];
    }
    int tmp = sqrt(sum);
    return tmp * tmp == sum;
}

void output() {
    for (int i = 0; i < 10; i++) {
        cout << a[i];
    }
    cout << endl; 
}

int main() {
    while (next_permutation(a, a + 10)) {
        if (a[0] == 0) continue;
        if (is_valid(a)) output();
    }
    cout << sqrt(2081549376) << " * " << sqrt(2081549376) << " = " << sqrt(2081549376) * sqrt(2081549376) << endl;
    return 0;
}
