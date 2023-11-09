#include<bits/stdc++.h>
using namespace std;


class disjointset{
    private:
    vector<int> size,rank,parent;

    public:
    
    disjointset(int n){
        size.resize(n+1,1);
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int ultimateparent(int n){
        if(parent[n] == n){
        return n;
        } 

        return parent[n] = ultimateparent(parent[n]);
    }

    void unionbyrank(int u,int v){
        int ulp_u = ultimateparent(u);
        int ulp_v = ultimateparent(v);

        if(ulp_u == ulp_v){
            return ;
        }

        else{
            if(rank[ulp_v] < rank[ulp_u]){
                parent[ulp_v] = ulp_u;
            }

            else if(rank[ulp_v] > rank[ulp_u]){
                parent[ulp_u] = ulp_v;
            }
            else{
                parent[ulp_u] = ulp_v;
                rank[ulp_v]++;
            }
        }
    }

    void unionbysize(int u,int v){
        int ulp_u = ultimateparent(u);
        int ulp_v = ultimateparent(v);

        if(ulp_u == ulp_v){
            return ;
        } 
        else{
            if(size[ulp_v] < size[ulp_u]){
                parent[ulp_v] = ulp_u;
                size[ulp_u]+= size[ulp_v];
            }
            else{
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
        }
    }
};

int main(){

    disjointset ds(7);
    ds.unionbyrank(0,2);
    ds.unionbyrank(3,4);
    ds.unionbyrank(4,2);

    if(ds.ultimateparent(3) == ds.ultimateparent(0)){
    cout << "same component";

    }

    else{
    cout <<"not the same";

    } 
}
