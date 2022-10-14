#include<bits/stdc++.h>
using namespace std;


//TIME COMPLEXITY : O(E log V + V log E)
class Graph{

int n;
vector<vector<pair<int,int>>> adj;

public: 

    Graph(int N) : n(N) {
        adj.resize(n);
    }

    void addEdge(int u,int v,int w){
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    void prims(){
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;

        //DSU to keep track of parent for each node
        vector<int> parent(n,-1);
        vector<int> rank(n,INT_MAX);

        vector<int> visited(n,0);

        pq.push({0,0});
        rank[0] = 0;

        while(!pq.empty()){

            int u = pq.top().second;
            pq.pop();

            if(visited[u] == 1)
                continue;

            visited[u] = 1;

            for(auto i : adj[u]){
                int v = i.first , w = i.second;
 
                if (visited[v] == 0 && rank[v] > w)
                {
                    rank[v] = w;
                    pq.push(make_pair(w, v));
                    parent[v] = u;
                }
            }
        }

        vector<int> mst[n];

        for(int i=0;i<n;i++){
            mst[parent[i]].push_back(i);
        }

        for(int i = 0;i<n;i++){
            if(mst[i].size()==0)
                continue;

            cout<<i<<": ";
            for(auto j:mst[i])
                cout<<j<<" ";
            cout<<endl;
        }
    }
};

int main(){

    Graph g(6);

    g.addEdge(0,2,8);
    g.addEdge(0,1,2);
    g.addEdge(1,2,4);
    g.addEdge(1,3,3);
    g.addEdge(2,4,2);
    g.addEdge(3,5,2);
    g.prims();

    return 0;
}