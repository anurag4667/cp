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

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>> edges;
        for(int i = 0;  i < V; i++){
            for(auto edg : adj[i]){
                edges.push_back({edg[1],{i,edg[0]}});
            }
        }
        
        sort(edges.begin(),edges.end());
        
        disjointset ds(V);
        int wt = 0;
        
        for(auto i : edges){
            if(ds.ultimateparent(i.second.first) != ds.ultimateparent(i.second.second)){
                wt+= i.first;
                ds.unionbyrank(i.second.first,i.second.second);
            }
        }
        
        return wt;
        // code here
    }
};
