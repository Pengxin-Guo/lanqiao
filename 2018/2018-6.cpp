/*************************************************************************
	> File Name: 2018-6.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月19日 星期二 21时08分22秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
    int n, h1, m1, s1, h2, m2, s2, hh1, mm1, ss1, hh2, mm2, ss2;
    char str1[30], str2[30];
    cin >> n;
    getchar();
    for (int i = 0; i < n; i++) {
        memset(str1, 0, sizeof(str1));
        memset(str2, 0, sizeof(str2));
        scanf("%[^\n]s", str1);
        getchar();
        scanf("%[\n]s", str2);
        getchar();
        cout << str2 << endl;
        h1 = (str1[0] - '0') * 10 + str1[1] - '0';
        m1 = (str1[3] - '0') * 10 + str1[4] - '0';
        s1 = (str1[6] - '0') * 10 + str1[7] - '0';
        h2 = (str1[9] - '0') * 10 + str1[10] - '0';
        m2 = (str1[12] - '0') * 10 + str1[13] - '0';
        s2 = (str1[15] - '0') * 10 + str1[16] - '0';
        if (str1[20] == '1') {
            hh1 = 24 - h1 + h2;
        } else if (str1[20] == '2') {
            hh1 = 48 - h1 + h2;
        } else {
            hh1 = h2 - h1;
        }
        mm1 = m2 - m1;
        ss1 = s2 - s1;

        h1 = (str2[0] - '0') * 10 + str2[1] - '0';
        m1 = (str2[3] - '0') * 10 + str2[4] - '0';
        s1 = (str2[6] - '0') * 10 + str2[7] - '0';
        h2 = (str2[9] - '0') * 10 + str2[10] - '0';
        m2 = (str2[12] - '0') * 10 + str2[13] - '0';
        s2 = (str2[15] - '0') * 10 + str2[16] - '0';
        if (str2[20] == '1') {
            hh2 = 24 - h1 + h2;
        } else if (str2[20] == '2') {
            hh2 = 48 - h1 + h2;
        } else {
            hh2 = h2 - h1;
        }
        mm2 = m2 - m1;
        ss2 = s2 - s1;
        cout << hh1 << " " << hh2 << endl;
        printf("%02d:%02d:%02d\n", (hh1 + hh2) / 2, (mm1 + mm2) / 2, (ss1 + ss2) / 2);
    }
    return 0;
}
