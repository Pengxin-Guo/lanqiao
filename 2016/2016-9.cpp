/*************************************************************************
	> File Name: 2016-9.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月22日 星期五 19时02分55秒
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;
#define MAX_N 1000

char str1[MAX_N + 5], str2[MAX_N + 5];
int dp[MAX_N + 5][MAX_N + 5];
int len;

int lcs(char *str1, char *str2) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (str1[i] == str2[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            else {
                dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }
    return dp[len][len];
}

int main() {
    cin >> str1;
    len = strlen(str1);
    for (int i = len - 1; i >= 0; i--) {
        str2[len - 1 - i] = str1[i];
    }
    int temp = lcs(str1, str2);
    cout << len - temp << endl;
    return 0;
}
