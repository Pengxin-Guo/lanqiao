/*************************************************************************
    > File Name: 5.cpp
    > Author: gpx
    > Mail: 1457495424@qq.com
    > Created Time: 2019年05月20日 星期一 20时30分57秒
************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 20000
int n;
struct node {
    int a, b;
};

vector<node> reg;

bool cmp(node n1, node n2) {
    return n1.b < n2.b;
}

int check(int x) {
    int k = 0;
    vector<node> tmp(reg);
    while (1) {
        bool found = false;
        for (int i = 0; i < tmp.size(); i++) {
            node now = tmp[i];
            int ta = now.a, tb = now.b;
            if (ta - x <= k && tb + x >= k) {
                found = true;
                int len = tb - ta;
                if (ta + x >= k) k += len;
                else k = tb + x;
                tmp.erase(tmp.begin() + i);
                break;
            }
        }
        if (!found || k >= MAX_N) break;
    }
    return k >= MAX_N;
}

// 00001111
double func() {
    int l = 0, r = MAX_N;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return r / 2.0;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a <<= 1;
        b <<= 1;
        reg.push_back({a, b});
    }
    sort(reg.begin(), reg.end(), cmp);
    cout << func() << endl;
    return 0;
}
