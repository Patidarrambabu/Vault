#include<bits/stdc++.h>
using namespace std;

class SegmentTree{
    int n;
    vector<long long int> ar,tree;
    // for count of min on segments
    vector<pair<int,long long int>> T;

    public:
        SegmentTree(int N):n(N),ar(N),tree(4*N),T(4*N){
        }
    
    void insert(){
        for(int i=0;i<n;i++){
            cin>>ar[i];
        }
    }
    void buildSumTree(int node,int s,int e){
        if(s == e){
            tree[node] = ar[s];
            return;
        }


        int mid = (s + e)/2;

        buildSumTree(2*node,s,mid);
        buildSumTree(2*node + 1,mid+1,e);


        // main code
        tree[node] = tree[2*node] + tree[2*node + 1];
    }
    void updateSumTree(int node,int s,int e,int i,int val){
        if(s == e){
            ar[s]  = val;
            tree[node] = val;
            return;
        }

        int mid = (s+e)/2;
        if( i <= mid){
            updateSumTree(2*node,s,mid,i,val);
        }else{
            updateSumTree(2*node+1,mid+1,e,i,val);
        }

        tree[node] = tree[2*node] + tree[2*node+1];
    }
    void printTree(){
        for(int i=1;i<4*n;i++)
            cout<<tree[i]<<" ";
        cout<<endl;
    }
    void printTree2(){
        for(int i=1;i<4*n;i++)
            cout<<T[i].first<<" "<<T[i].second<<endl;
        cout<<endl;
    }
    void printArray(){
        for(auto i:ar)
            cout<<i<<" ";
        cout<<endl;
    }
    long long int getSumInRange(int node,int s,int e,int l, int r){
        if(s>r || e<l)
            return 0;

        if(l<=s && e<=r)
            return tree[node];

        int mid = (s+e)/2;

        return getSumInRange(2*node,s,mid,l,r) + getSumInRange(2*node+1,mid+1,e,l,r);
    }
    void buildMaxTree(int node,int s,int e){
     if(s == e){
         tree[node] = ar[s];
         return;
     }

     int mid = (s+e)/2;
     buildMaxTree(2*node,s,mid);
     buildMaxTree(2*node+1,mid+1,e);

     tree[node] = max( tree[2*node] , tree[2*node+1] );
    }
    int getMaxInRange(int node,int s,int e,int l,int r){
     if(e<l || s>r)
         return INT_MIN;
     if(l<=s && e<=r)
         return tree[node];

     int mid = (s+e)/2;

     return max( getMaxInRange(2*node,s,mid,l,r) , getMaxInRange(2*node+1,mid+1,e,l,r));
    }
    void updateMaxTree(int node,int s,int e,int i,int v){
     if(s == e){
         ar[s]  = v;
         tree[node] = v;
         return;
     }

     int mid = (s+e)/2;
     if( i <= mid){
         updateMaxTree(2*node,s,mid,i,v);
     }else{
         updateMaxTree(2*node+1,mid+1,e,i,v);
     }

     tree[node] = max(tree[2*node] , tree[2*node+1]);    
    }
    void buildMinTree(int node,int s,int e){
     if(s == e){
         tree[node] = ar[s];
         return;
     }

     int mid = (s+e)/2;
     buildMinTree(2*node,s,mid);
     buildMinTree(2*node+1,mid+1,e);

     tree[node] = min( tree[2*node] , tree[2*node+1] );
    }
    int getMinInRange(int node,int s,int e,int l,int r){
     if(e<l || s>r)
         return INT_MAX;
     if(l<=s && e<=r)
         return tree[node];

     int mid = (s+e)/2;

     return min( getMinInRange(2*node,s,mid,l,r) , getMinInRange(2*node+1,mid+1,e,l,r));
    }
    void updateMinTree(int node,int s,int e,int i,int v){
     if(s == e){
         ar[s]  = v;
         tree[node] = v;
         return;
     }

     int mid = (s+e)/2;
     if( i <= mid){
         updateMinTree(2*node,s,mid,i,v);
     }else{
         updateMinTree(2*node+1,mid+1,e,i,v);
     }

     tree[node] = min(tree[2*node] , tree[2*node+1]);    
    }
    void buildMinCountTree(int node,int s,int e){
     if(s == e){
         T[node] = { ar[s] , 1};
         return;
     }

     int mid = (s+e)/2;
     buildMinCountTree(2*node,s,mid);
     buildMinCountTree(2*node+1,mid+1,e);

     pair<int,long long int> a = T[2*node] , b = T[2*node+1];

     if( a.first < b.first ){
     	T[node] = a;
     }else if(a.first > b.first){
     	T[node] = b;
     }else{
     	T[node] = { a.first , a.second + b.second };
     }
    }
    pair<int,long long int> getMinCountInRange(int node,int s,int e,int l,int r){
     if(e<l || s>r)
         return {INT_MAX,0};
     if(l<=s && e<=r)
         return T[node];

     int mid = (s+e)/2;

     pair<int,long long int> a = getMinCountInRange(2*node,s,mid,l,r) 
     , b = getMinCountInRange(2*node+1,mid+1,e,l,r);

     if( a.first < b.first ){
     	return  a;
     }else if(a.first > b.first){
     	return b;
     }else{
     	return { a.first , a.second + b.second };
     }
    }
    void updateMinCountTree(int node,int s,int e,int i,int v){
     if(s == e){
         ar[s]  = v;
         T[node] = {v,1};
         return;
     }

     int mid = (s+e)/2;
     if( i <= mid){
         updateMinCountTree(2*node,s,mid,i,v);
     }else{
         updateMinCountTree(2*node+1,mid+1,e,i,v);
     }

     pair<int,long long int> a = T[2*node] , b = T[2*node+1]; 
         if(a.first < b.first){
            T[node] = a;
         }else if(a.first > b.first){
            T[node] = b;
         }else{
            T[node] = { a.first , a.second + b.second };
         }
    }
};


int main(){

    int n , q;
    cin>> n >> q;
    SegmentTree Stree(n);
    Stree.insert();
    Stree.buildMinCountTree(1,0,n-1);

    while(q--){
        int t , a ,b;
        cin>>t >>a >>b;

        switch(t){
            case 1: {
                // cout<<a<<" "<<b<<endl;
                Stree.updateMinCountTree(1,0,n-1,a,b);
                // Stree.printTree();
            } break;
            case 2: {
            	pair<int,long long int> ans = Stree.getMinCountInRange(1,0,n-1,a,b-1);
                cout<<ans.first<<" "<<ans.second<<endl;
            } break;
        }

   }

    return 0;
}


int mod = 1000000007;
#define long long long int

struct Node{
  long pref;
  long suf;
  long sum;
  long ans;
};

class SG{

  vector<long> ar;
  vector<Node> tree;
  
  int N;

  public:
    SG(int n): N(n) , ar(n) , tree(4*n){
        for(int i=0;i<n;i++)
          cin>>ar[i];
    }
    void build(int n,int s,int e){
      if(s == e){
          if(ar[s]<=0){
            tree[n] = {0,0,ar[s],0};
          }else{
            tree[n] = {ar[s],ar[s],ar[s],ar[s]};
          }      
          return; 
      }

      int mid = (s+e)/2;
      build(2*n,s,mid);
      build(2*n+1,mid+1,e);

      long pref,suf,sum,ans;
      pref = max( tree[2*n].pref , tree[2*n].sum + tree[2*n+1].pref);
      suf = max( tree[2*n+1].suf , tree[2*n+1].sum + tree[2*n].suf);
      sum = tree[2*n].sum + tree[2*n+ 1].sum ;
      ans = max( tree[2*n].suf + tree[2*n+1].pref , max(tree[2*n].ans , tree[2*n+1].ans));

      tree[n] = {pref,suf,sum,ans};
    }
    void update(int n,int s,int e,int i,long v){
      if(s == e){
          ar[s] = v;

          if(ar[s]<=0){
            tree[n] = {0,0,ar[s],0};
          }else{
            tree[n] = {ar[s],ar[s],ar[s],ar[s]};
          }     

          return;  
      }

      int mid = (s+e)/2;

      if(i<=mid)
        update(2*n,s,mid,i,v);
      else
        update(2*n+1,mid+1,e,i,v);

      long pref,suf,sum,ans;
      pref = max( tree[2*n].pref , tree[2*n].sum + tree[2*n+1].pref);
      suf = max( tree[2*n+1].suf , tree[2*n+1].sum + tree[2*n].suf);
      sum = tree[2*n].sum + tree[2*n+ 1].sum ;
      ans = max( tree[2*n].suf + tree[2*n+1].pref , max(tree[2*n].ans , tree[2*n+1].ans));

      tree[n] = {pref,suf,sum,ans};
    }
    void getMax(){

      cout<<tree[1].ans<<endl;
    }
    void printTree(){
      for(auto i: tree)
        cout<<i.pref<<" "<<i.suf<<" "<<i.sum<<" "<<i.ans<<endl;
      cout<<endl;
    }
};


int main(){

  int N,M;
  cin>>N>>M;

  SG sg(N);
  sg.build(1,0,N-1);
  sg.getMax();
  // sg.printTree();

  while(M--){
    int i;
    long v;
    cin>>i>>v;

    sg.update(1,0,N-1,i,v);
    sg.getMax();
  }
  
  return 0;
}
