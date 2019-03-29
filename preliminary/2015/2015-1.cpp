/*************************************************************************
	> File Name: 2015-1.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月22日 星期五 20时23分25秒
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
    for (int i = 1; i * i < 1000; i++) {
        for (int j = i; j * j < 1000; j++) {
            for (int k = j; k * k < 1000; k++) {
                if (i * i + j * j + k * k == 1000) {
                    cout << i << " " << j << " " << k << endl;
                }
            }
        }
    }
    return 0;
}
