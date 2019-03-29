/*************************************************************************
	> File Name: 2014-6.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月23日 星期六 16时05分42秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

char arr[8] = {'2', '2', '3','3', '4', '4', 'A', 'A'};

void output() {
    for (int i = 0; i < 8; i++) {
        cout << arr[i];
    }
    cout << endl;
    return ;
}

int is_valid() {
    int ind[3] = {0, 0};
    for (int i = 0; i < 8; i++) {
        if (arr[i] == 'A') ind[++ind[0]] = i;
    }
    if (ind[2] - ind[1] != 2) return 0;
    ind[0] = 0;
    for (int i = 0; i < 8; i++) {
        if (arr[i] == '2') ind[++ind[0]] = i;
    }
    if (ind[2] - ind[1] != 3) return 0;
    ind[0] = 0;
    for (int i = 0; i < 8; i++) {
        if (arr[i] == '3') ind[++ind[0]] = i;
    }
    if (ind[2] - ind[1] != 4) return 0;
    ind[0] = 0;
    for (int i = 0; i < 8; i++) {
        if (arr[i] == '4') ind[++ind[0]] = i;
    }
    if (ind[2] - ind[1] != 5) return 0;
    return 1;
}

int main() {
    do {
        if (is_valid()) {
            output();
            break;
        }
    } while (next_permutation(arr, arr + 8));
    return 0;
}
