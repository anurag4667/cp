#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<vector<int>> &adj,vector<int> &vis,stack<int> &st){
        vis[node] = 1;

        for(auto i : adj[node]){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }
        st.push(node);
    }

    void dfs2(int node,vector<vector<int>> &adj,vector<int> &vis){
        vis[node] = 1;

        for(auto i : adj[node]){
            if(!vis[i]){
                dfs2(i,adj,vis);
            }
        }
    }
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        
        vector<int> vis(V,0);
        stack <int> st;
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }

        vector<vector<int>> newadj(V);
        for(int i = 0; i < V; i++){
            vis[i] = 0;
            for(auto node : adj[i]){
                newadj[node].push_back(i);
            }
        }

        int scc = 0;

        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!vis[node]){
                scc++;
                dfs2(node,newadj,vis);
            }
        }

        return scc;
        //code here
    }