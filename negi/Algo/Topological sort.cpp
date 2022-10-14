#include<bits/stdc++.h>
using namespace std;


//V: no of vertices, E: no of Edges
//Time Complexity: O(V+E) 

class Graph
{
    int v;
    list<int>* adj;

    void recur(int v,vector<int> &vis,stack<int> &s){
     vis[v] = true;

       for(int i : adj[v]){
         if(vis[i] == 0)
            recur(i,vis,s);
       }

     s.push(v);
    }

public:
    Graph(int n) : v(n) {
        adj = new list<int>[n];
    };

    void add(int u,int v){
        adj[u].push_back(v);
    }

    void topologicalSort(){
        vector<int> vis(v,0);
        stack<int> st;

        for(int i=0;i<v;i++){
            if(vis[i] == 0)
                recur(i,vis,st);
        }


        while(!st.empty()){
            cout<<(char)( st.top() + 65) <<" ";
            st.pop();
        }
    }
};

int main(){

    Graph g(9);

    // 0 : A , 1: b ....

    g.add(0,2); g.add(0,3);
    g.add(1,3); g.add(1,4);
    g.add(3,5); g.add(3,6);
    g.add(6,8);
    g.add(7,8);

    g.topologicalSort();

    return 0;
}