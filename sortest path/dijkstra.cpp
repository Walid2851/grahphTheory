#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<set>

using namespace std;

const int N =1e6+10;
const int INF = 1e9+10;

vector<pair<int,int> >g[N];
vector<int>visit(N,0);
vector<int>dist(N,INF);

void dijkstra(int source){
    set<pair<int,int> > st;
    st.insert(make_pair(0,source));
    dist[source]=0;
    while(st.size()>0){
        auto node = * st.begin();
        int v = node.second;
        int dist_v = node.first;
        st.erase(st.begin());

        if(visit[v])continue;
        visit[v]=1;
        for(auto child:g[v]){
            int curr_v = child.first;
            int wt = child.second;
            if(wt+dist[v] < dist[curr_v]){
                dist[curr_v]=dist[v]+wt;
                st.insert(make_pair(dist[curr_v],curr_v));
            }
        }
    }
}

int main(){

    int v,e;
    cin >> v >> e;

    for(int i=0;i<e;i++){
        int x,y,wt;
        cin >> x >> y >> wt;
        g[x].push_back(make_pair(y,wt));
        //g[y].push_back(x);
    }

    dijkstra(1);

    for(int i=1;i<=v;i++)cout << dist[i] << " ";

    return 0;
}