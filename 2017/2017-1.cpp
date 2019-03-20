/*************************************************************************
	> File Name: 2017-1.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月20日 星期三 10时38分20秒
 ************************************************************************/

#include <iostream>
using namespace std;

char mat[15][15];

int main() {
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            cin >> mat[i][j];
            cout << mat[i][j];
        }
        cout << endl;
    }
    return 0;
}
