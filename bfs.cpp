#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int N =1e6+10;

vector<int>g[N];
vector<int>visit(N,0);
vector<int>dist(N);

void bfs(int source){
    queue<int>q;
    q.push(source);
    visit[source]=1;
    dist[source]=0;

    while(!q.empty()){
        int curr_v=q.front();
        q.pop();

        for(auto child:g[curr_v]){
            if(!visit[child]){
                q.push(child);
                visit[child]=1;
                dist[child]=dist[curr_v]+1;
            }
        }

    }
}

int main(){

    int v,e;
    cin >> v >> e;

    for(int i=0;i<e;i++){
        int x,y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    bfs(1);

    for(int i=1;i<=v;i++){
        cout << visit[i] << " " << dist[i] << endl;
    }

    return 0;
}