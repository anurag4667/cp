#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int sum = 0;
        
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> pq;
        
        vector<int> vis(V,0);
        pq.push({0,0});
        
        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if(!vis[node]){
                vis[node] = 1;
                sum += wt;
                for(auto i : adj[node]){
                    if(!vis[i[0]]){
                        pq.push({i[1],i[0]});
                    }
                }
            }
            
        }
        
        return sum;
        // code here
    }
};