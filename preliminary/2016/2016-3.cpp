/*************************************************************************
	> File Name: 2016-3.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月22日 星期五 16时07分58秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

bool is_valid(int *num) {
    if (abs(num[1] - num[0]) == 1) return false;
    if (abs(num[3] - num[0]) == 1) return false;
    if (abs(num[4] - num[0]) == 1) return false;
    if (abs(num[5] - num[0]) == 1) return false;

    if (abs(num[2] - num[1]) == 1) return false;
    if (abs(num[4] - num[1]) == 1) return false;
    if (abs(num[5] - num[1]) == 1) return false;
    if (abs(num[6] - num[1]) == 1) return false;

    if (abs(num[5] - num[2]) == 1) return false;
    if (abs(num[6] - num[2]) == 1) return false;
    
    if (abs(num[4] - num[3]) == 1) return false;
    if (abs(num[7] - num[3]) == 1) return false;
    if (abs(num[8] - num[3]) == 1) return false;

    if (abs(num[5] - num[4]) == 1) return false;
    if (abs(num[7] - num[4]) == 1) return false;
    if (abs(num[8] - num[4]) == 1) return false;
    if (abs(num[9] - num[4]) == 1) return false;

    if (abs(num[6] - num[5]) == 1) return false;
    if (abs(num[8] - num[5]) == 1) return false;
    if (abs(num[9] - num[5]) == 1) return false;
    
    if (abs(num[9] - num[6]) == 1) return false;

    if (abs(num[8] - num[7]) == 1) return false;
    
    if (abs(num[9] - num[8]) == 1) return false;
   
    return true;
}

int main() {
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int ans = 0;
    do {    
        if (is_valid(arr)) ans++;
    } while (next_permutation(arr, arr + 10));
    cout << ans << endl;
    return 0;
}
