#include<iostream>
#include<vector>

using namespace std;

const int N = 1e5+10;
vector<int> g[N];
vector<int>visit(N,0);

void dfs(int source){
    //cout << source << " ";
    visit[source]=1;
    for(auto child:g[source]){
        if(visit[child])continue;
        dfs(child);
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

   //for(auto x:g[1])cout << x << endl;

   dfs(1);
}