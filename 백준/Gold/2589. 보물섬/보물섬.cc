//BOJ 2589
//BFS로 풀어보기
#include <bits/stdc++.h>
using namespace std;

string arr[55];
int dist[55][55];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int n,m;
int mx = -1;

int main(){
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] != 'L') continue;
            for(int k = 0; k < n; k++){
                fill(dist[k],dist[k] + m, 0);
            }
            queue <pair<int,int>> q;
            dist[i][j] = 1;
            q.push({i,j});
            while(!q.empty()){
                auto cur = q.front();
                q.pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(arr[nx][ny] == 'W') continue;
                    if(dist[nx][ny] > 0) continue;
                    dist[nx][ny] = dist[cur.first][cur.second] + 1;
                    q.push({nx,ny});
                    if(dist[nx][ny] > mx){
                        mx = dist[nx][ny];
                    }
                }
            }
        }
    }
    cout<<mx-1;
}