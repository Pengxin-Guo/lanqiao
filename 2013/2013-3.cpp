/*************************************************************************
	> File Name: 2013-3.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月18日 星期一 11时01分49秒
 ************************************************************************/

#include <iostream>
using namespace std;

int arr[6][6];

int main() {
    arr[1][1] = 1;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 5; j++) {
            arr[i][j] += arr[i - 1][j] + arr[i][j - 1];
        }
    }
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 5; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << arr[4][5] << endl;
    return 0;
}
