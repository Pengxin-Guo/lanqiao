/*************************************************************************
	> File Name: 2014-1.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月23日 星期六 11时41分42秒
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
    for (int i = 1; i < 100; i++) {
        for (int j = i; j <= i + 8; j++) {
            if (i * j == (i + j) * 6) {
                cout << i << " " << j << endl;
                cout << i * j << " " << (i + j) * 6 << endl;
                return 0;
            }
        }
    }
    return 0;
}
