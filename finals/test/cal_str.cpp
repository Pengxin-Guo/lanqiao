/*************************************************************************
	> File Name: cal_str.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年05月02日 星期四 17时19分26秒
 ************************************************************************/
// 计算表达式的值

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAX_N 1000
#define INF 0x3f3f3f3f

// 利用递归的思想来求表达式的值
int calc(char *str, int l, int r) {
    int pos = -1, temp_prior = 0, prior = INF - 1;
    for (int i = l; i <= r; i++) {
        int cur_prior = INF;
        switch (str[i]) {
            case '(' : temp_prior += 100; break;
            case ')' : temp_prior -= 100; break;
            case '+' : cur_prior = temp_prior + 1; break;
            case '-' : cur_prior = temp_prior + 1; break;
            case '*' : cur_prior = temp_prior + 2; break;
            case '/' : cur_prior = temp_prior + 2; break;
        }
        if (cur_prior <= prior) {
            prior = cur_prior;
            pos = i;                                           // 找到中间那个位置，分割为两部分求解
        }
    }
    if (pos == -1) {                                           // 此部分没有运算符的时候
        int num = 0;
        for (int i = l; i <= r; i++) {
            if (str[i] < '0' || str[i] > '9') continue;
            num = num * 10 + str[i] - '0';
        }
        return num;
    } else {
        int a = calc(str, l, pos - 1);                         // 递归计算左部分的值
        int b = calc(str, pos + 1, r);                         // 递归计算右部分的值
        switch (str[pos]) {
            case '+' : return a + b;
            case '-' : return a - b;
            case '*' : return a * b;
            case '/' : return a / b;
        }
    }
    return 0;
}

int main() {
    char str[MAX_N + 5];
    scanf("%[^\n]s", str);
    cout << calc(str, 0, strlen(str) - 1) << endl;
    return 0;
}
