/*************************************************************************
	> File Name: 2017-2.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年03月20日 星期三 10时51分53秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

int eend[9] = {0, 8, 7, 6, 5, 4, 3, 2, 1};
int ans;
set<string> vis;

struct Node {
    int data[9];
    int cnt;
    Node(int *num, int n) {
        for (int i = 0; i < 9; i++) {
            data[i] = num[i];
        }
        cnt = n;
    }
};

int is_valid(Node node) {
    for (int i = 0; i < 9; i++) {
        if (node.data[i] != eend[i]) return 0;
    }
    return 1;
}

string to_str(Node node) {
    string ret;
    for (int i = 0; i < 9; i++) {
        char c = node.data[i] + '0';
        ret = ret + c;
    }
    return ret;
}

void bfs(Node node) {
    queue<Node> q;
    q.push(node);
    string str = to_str(node);
    vis.insert(str);
    while (!q.empty()) {
        Node nn = q.front();
        q.pop();
        cout << nn.cnt << endl;
        if (is_valid(nn)) {
            ans = nn.cnt;
            return ;
        }
        int ind;
        for (int i = 0; i < 9; i++) {
            if (nn.data[i] == 0) {
                ind = i;
                break;
            }
        }
        int *arr1 = (int *)malloc(sizeof(int) * 9);
        for (int i = 0; i < 9; i++) {
            arr1[i] = nn.data[i];
        }
        swap(arr1[ind], arr1[(ind + 1) % 9]);
        Node temp1(arr1, nn.cnt + 1);
        string t1 = to_str(temp1);
        if (!vis.count(t1)) {
            q.push(temp1);
            vis.insert(t1);
        }

        for (int i = 0; i < 9; i++) {
            arr1[i] = nn.data[i];
        }
        swap(arr1[ind], arr1[(ind + 8) % 9]);
        Node temp2(arr1, nn.cnt + 1);
        string t2 = to_str(temp2);
        if (!vis.count(t2)) {
            q.push(temp2);
            vis.insert(t2);
        }

        for (int i = 0; i < 9; i++) {
            arr1[i] = nn.data[i];
        }
        swap(arr1[ind], arr1[(ind + 2) % 9]);
        Node temp3(arr1, nn.cnt + 1);
        string t3 = to_str(temp3);
        if (!vis.count(t3)) {
            q.push(temp3);
            vis.insert(t3);
        }

        for (int i = 0; i < 9; i++) {
            arr1[i] = nn.data[i];
        }
        swap(arr1[ind], arr1[(ind + 7) % 9]);
        Node temp4(arr1, nn.cnt + 1);
        string t4 = to_str(temp4);
        if (!vis.count(t4)) {
            q.push(temp4);
            vis.insert(t4);
        }
    }
    return ;
}

int main() {
    int *begin = (int *)malloc(sizeof(int) * 9);
    for (int i = 0;  i < 9; i++) {
        begin[i] = i;
    }
    Node node(begin, 0);
    bfs(node);
    cout << ans << endl;
    return 0;
}
