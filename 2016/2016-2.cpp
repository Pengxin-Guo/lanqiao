/*************************************************************************
	> File Name: 2016-2.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月22日 星期五 15时52分44秒
 ************************************************************************/

#include <iostream>
using namespace std;

int is_valid(int age) {
    int num = 0;
    while (num < 236) {
        num += age;
        age += 1;
    }
    return num == 236;
}

int main() {
    int age = 1;
    while (1) {
        if (is_valid(age)) {
            cout << age << endl;
            break;
        }
        age += 1;
    }
    return 0;
}
