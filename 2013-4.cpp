/*************************************************************************
	> File Name: 2013-4.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月18日 星期一 20时23分02秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int rev[10] = {0, 1, 5, -1, -1, 2, 9, -1, 8, 6};

struct Node {
    int before, last, sub;
    Node (int x, int y, int z) : before(x), last(y), sub(z) {}
};

int fit(int x) {
    while (x) {
        if (x % 10 == 3 || x % 10 == 4 || x % 10 == 7) return 0;
        x /= 10;
    }
    return 1;
}

int reverse(int x) {
    int num = 0;
    while (x) {
        num = num * 10 + rev[x % 10];
        x /= 10;
    }
    return num;
}

int main() {
    vector<Node> v;
    for (int i = 1000; i <= 9999; i++) {
        if (i % 10 == 0) continue;
        if (!fit(i)) continue;
        int r = reverse(i);
        int temp = r - i;
        if (!(temp > 800 && temp < 900) && !(temp > -300 && temp < -200)) continue;
        Node node(i, r, temp);
        v.push_back(node);
    }
    int x, y;
    for (int i = 0; i < v.size(); i++) {
        //cout << v[i].before << " " << v[i].last << " " << v[i].sub << endl;
        for (int j = i + 1; j < v.size(); j++) {
            if (v[i].sub + v[j].sub == 558) {
                x = i;
                y = j;
            }
        }
    }
    cout << v[x].before << " " << v[x].last << " " << v[x].sub << endl;
    cout << v[y].before << " " << v[y].last << " " << v[y].sub << endl;
    return 0;
}
