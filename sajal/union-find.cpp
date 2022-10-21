#include<bits/stdc++.h>
using namespace std;

///---------------------------------------------------------
///---------------------------------------------------------
///---------------------------------------------------------
///---------------------------------------------------------



///---------------------------------------------------------
// void cswap(int ar[],int i,int j){
// 	int t = ar[i];
// 	ar[i] = ar[j];
// 	ar[j] = t;
// }

// int part(int ar[],int l,int h){
// 	int w = l;
// 	int pi = ar[h];

// 	for(int i=l;i<h;i++){
// 		if(ar[i]<pi){
// 			cswap(ar,i,w);
// 			w++;
// 		}
// 	}
// 	cswap(ar,w,h);

// 	return w;
// }

// int kMax(int ar[],int n,int k){
// 	int l = 0 , h = n-1;
// 	int t =  n - k;

// 	while(l<h){
// 		int p = part(ar,l,h);

// 		if(p < t)
// 			l = l + 1;
// 		else if(p>t)
// 			h = h - 1;
// 		else
// 			return ar[p];
// 	}

// 	return -1;
// }


///---------------------------------------------------------
// class UF{
//     vector<int> parent;

// public:
//     UF(int N) : parent(N) {
//         for(int i=1;i<N;i++) parent[i] = i;   
//     }

//     void Union(int i,int j){
//         int a = parent[i];
//         int b = parent[j];


//         if(a==b)
//             return;

//         if(a>b)
//             parent[b] = a;
//         else
//             parent[a] = b;
//     }

//     int find(int i){
//         return parent[i] = ( parent[i] == i ? i : find(parent[i]));
//     }

//     int getMax(int i){
//         return find(i);
//     }

// };


// void findMaxValueOfSet(vector<pair<int,int>> ar, vector<int> q,int R, int N,int M){
//     UF uf(R+1);

//     for(auto i:ar)
//         uf.Union(i.first,i.second);
    
//     for(auto i:q){
//         cout<<uf.getMax(i)<<" ";
//     }
// }

// int main(){

//     int R = 5;
//     vector<pair<int, int> > arr{ { 1, 2 },
//                                  { 2, 3 },
//                                  { 4, 5 } };

//     vector<int> queries{ 2, 4, 1, 3 };
//     int N = arr.size();
//     int M = queries.size();
 
//     findMaxValueOfSet(arr, queries, R, N, M);
    
//     return 0;
// }

///---------------------------------------------------------
// class UF{
//     vector<int> parent;
//     int size;

// public:
//     UF(int N):parent(N),size(N-2){
//         for(int i=1;i<=N;i++)
//             parent[i]= i;
//     }

//     void Union(int i,int j){
//         int a = find(i);
//         int b = find(j);

//         parent[a] = b; 
//     }


//     int find(int i){
//         return parent[i] = ( parent[i] == i ? i : find(parent[i]) );
//     }

//     int getRight(int i){
//         int a = find(i);
//         if(a > size)
//             return -1;

//         return a;
//     }
// };


// void Queries(vector<pair<int,int>> q,int N,int Q){

//     UF uf(N+2);

//     for(auto i : q){
//         if(i.first == 1){
//             uf.Union(i.second,i.second+1);
//         }else{
//             cout<<uf.getRight(i.second)<<" ";
//         }
//     }
// }

// int main(){

//     int N = 5;
//     vector<pair<int, int> > queries{
//         {2, 1}, {1, 3}, {2, 3}, {1, 2}, {2, 2}, {1, 5}, {2, 5}
//     };
//     int Q = queries.size();
 
//     Queries(queries, N, Q);
//     return 0;
// }




///---------------------------------------------------------
// class UnionFind{

// vector<int> parent;
// vector<int> rank;
// vector<int> cost;

// public:
//     UnionFind(int N ,vector<int> c):parent(N),rank(N),cost(N){
//         for( int i=1; i <= N ; i++ ){
//             parent[i] = i;
//             rank[i] = 0;
//             cost[i] = c[i-1];
//         }
//      }
//      int find(int i){
//         return parent[i] = ( parent[i] == i?i:find(parent[i]));
//      }

//      void Union(int i,int j){
//         int a = find(i);
//         int b = find(j);

//         if(rank[a] == rank[b])
//             rank[a]++;
//         if(rank[a]>rank[b]){
//             parent[b] = a;
//             if(cost[a]>=0 && cost[b]>=0)
//                 cost[a] = min(cost[a],cost[b]);
//             else if(cost[a]<0 && cost[b]>=0)
//                 cost[a] = cost[b];
//             else if(cost[a]>=0 && cost[b]<0)
//                 cost[a] = cost[a];
//             else
//                 cost[a] = max(cost[a],cost[b]);
//         }
//         else{
//             parent[a] = b;

//             if(cost[a]>=0 && cost[b]>=0)
//                 cost[b] = min(cost[a],cost[b]);
//             else if(cost[a]<0 && cost[b]>=0)
//                 cost[b] = cost[b];
//             else if(cost[a]>=0 && cost[b]<0)
//                 cost[b] = cost[a];
//             else
//                 cost[b] = max(cost[a],cost[b]);
//         }
//      }

//      int getCost(int i){ return cost[i]; }
// };

// void findMinCost(vector<pair<int,int>> G,vector<int> c,int N,int M){
//     UnionFind uF(N+1,c);

//     for(auto i:G)
//         uF.Union(i.first,i.second);

//     set<int> s;
//     for(int i=1;i<N+1;i++)
//             s.insert(uF.find(i));
    
//     bool flag = false;
//     pair<int,int> mn = { 0 , INT_MAX };

//     for(auto i: s){
//         if(uF.getCost(i)<0)
//             flag = true;

//         if(mn.second>uF.getCost(i))
//             mn = {i,uF.getCost(i)};
//     }

//     int minCost = 0;

//     if(!flag || (flag && s.size() == 1)){
//         for(auto i:s){
//             if(mn.first !=i){
//                 minCost+= (uF.getCost(i) + mn.second);
//             }
//         }
//         cout<<minCost<<endl;
//     }else{
//         cout<<-1<<endl;
//     }

// }

// int main(){
//     int N = 6;
//     vector<pair<int,int>> G = {
//         { 3, 1 }, { 2, 3 }, { 2, 1 },
//         { 4, 5 }, { 5, 6 }, { 6, 4 }
//     };

//     vector<int> cost{ 2, 1, 5, 3, 2, 9 };
//     int M = G.size();
 
//     findMinCost(G, cost, N, M);
//     return 0;
// }





///---------------------------------------------------------
// class UnionFind{
//     vector<int> parent;
//     vector<int> rank;

// public:
//     UnionFind(int N):parent(N),rank(N){
//         for(int i=0;i<N;i++){
//             parent[i] = i;
//             rank[i] = 0;
//         }
//     };

//     void makeSet(int i,int j){
//         int a = parent[i];
//         int b = parent[j];

//         if(rank[a]==rank[b])
//             rank[a]++;

//         if(rank[a]>rank[b])
//             parent[b] = a;
//         else
//             parent[a] = b;
//     }  

//     int find(int i){
//         return parent[i] = (parent[i]==i?parent[i]:find(parent[i]));
//     }
// };

// void numOfDistinctStrings(string st[],int N){

//     vector<bool> cur(26,false);
//     vector<bool> fin(26,false);
//     UnionFind uF(27);

//     for(int i=0;i<N;i++){
        
//         for(int j=0;j<26;j++)
//             cur[j] = false;

//         for(char ch : st[i])
//             cur[ch-'a'] = true;

//         for(int j=0;j<26;j++)
//             if(cur[j]){
//                 fin[j] = true;
//                 uF.makeSet(st[i][0] - 'a' , j);
//             }
//     }

//     int dis = 0;
//     for(int i=0;i<26;i++){
//         if(fin[i] && uF.find(i) == i)
//             dis++;
//     }

//     cout<<dis<<" ";
// }

// int main(){
//     string arr[] = { "a", "ab", "b", "d" };
//     int N = sizeof(arr) / sizeof(arr[0]);
//     numOfDistinctStrings(arr, N);
//     return 0;
// }




///---------------------------------------------------------
// class unionFind{

//     vector<int> parent;
//     vector<int> rank;

//     // no of sets
//     int count;
//     // time when all became friends
//     int time;

// public:
//     unionFind(int N):parent(N),rank(N),count(N){
//         time = 0;
//         for(int i=0;i<N;i++)
//             parent[i] = i , rank[i] = 1;
//     }

//     void makeSet(int i,int j,int uT){

//         if(count == 1)
//             return;

//         int a = find(i);
//         int b = find(j);

//         if(a!=b){
//             if(rank[a]<rank[b])
//                 parent[a] = b;
//             else if(rank[a]>rank[b])
//                 parent[b] = a;
//             else{
//                 parent[a] = b;
//                 rank[a]++;
//             }

//             time = uT;
//             count--;
//         }
//     }

//     int find(int i){
//         return parent[i] = (parent[i] == i ? i : find(parent[i])) ;
//     }

//     int getCount(){return count;}
//     int getTime(){return time;}
// };


// int earliestTime(vector<vector<int>> ar,int N){
    
//     unionFind uF(N);

//     sort(ar.begin(), ar.end(),[](vector<int> &a,vector<int> &b)->bool{
//         return a[2]<b[2];
//     });

//     for(auto i:ar){
//         uF.makeSet(i[0],i[1],i[2]);
//     }

//     if(uF.getCount() !=1)
//         return -1; 

//     return uF.getTime();
// }

// int main()
// {
//     int N = 6;
//     vector<vector<int> > arr
//         = { { 0, 1, 4 }, { 3, 4, 5 },
//             { 2, 3, 14 }, { 1, 5, 24 },
//             { 2, 4, 12 }, { 0, 3, 42 },
//             { 1, 2, 41 }, { 4, 5, 11 } };
 
//     cout << earliestTime(arr, N);
 
//     return 0;
// }