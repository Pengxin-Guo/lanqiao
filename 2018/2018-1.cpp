/*************************************************************************
	> File Name: 2018-1.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月19日 星期二 20时11分36秒
 ************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int num1, num2 = 0;
    num1 = pow(2, 19);
    for (int i = 0; i <= 19; i++) {
        num2 += pow(2, i);
    }
    int g = gcd(num2, num1);
    cout << g << endl;
    cout << num2 <<  " " << num1 << endl;
    return 0;
}
