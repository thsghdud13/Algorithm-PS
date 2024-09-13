#include <bits/stdc++.h>
using namespace std;

int n;
int a[3];
int visited[64][64][64];
int _a[6][3] = {
    {9, 3, 1},
    {9, 1, 3},
    {3, 1, 9},
    {3, 9, 1},
    {1, 3, 9},
    {1, 9, 3},
};

struct A{
    int a, b, c;
};

int main(){
    cin>>n;
    for(int i = 0; i < n; i++){
        int k;
        cin>>k;
        a[i] = k;
    }
    queue<A> q;
    q.push({a[0],a[1],a[2]});
    visited[a[0]][a[1]][a[2]] = 1;
    while (!q.empty()) {
        A cur = q.front();
        q.pop();
        if(visited[0][0][0]) break;
        for(int i = 0; i < 6; i++){
            int na = max(0, cur.a - _a[i][0]);
            int nb = max(0,cur.b - _a[i][1]);
            int nc = max(0,cur.c - _a[i][2]);
            if(visited[na][nb][nc]) continue;
            visited[na][nb][nc] = visited[cur.a][cur.b][cur.c] + 1;
            q.push({na,nb,nc});
        }
    }

    cout<< visited[0][0][0] - 1;

}