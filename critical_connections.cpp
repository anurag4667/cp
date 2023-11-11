class Solution {
public:
    void dfs(int node ,vector<int> &vis,vector<int> &par,vector<int> &disc,vector<int> &low,vector<vector<int>> &ans,vector<int> adj[],int &time){
        vis[node] = 1;
        disc[node] = low[node] = time;
        time++;

        for(auto i : adj[node]){

            if(par[node] == i) continue;

            else if(vis[i]){
                low[node] = min(low[node],disc[i]);
            }
            else{
                par[i] = node;
                dfs(i,vis,par,disc,low,ans,adj,time);
                low[node] = min(low[node],low[i]);

                if(low[i] > disc[node]){
                    ans.push_back({i,node});
                }
            }
        }

    }   

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<int> adj[n];

        for(auto i : connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        vector<int> vis(n,0);
        vector<int> par(n,-1);
        vector<int> disc(n,0);
        vector<int> low(n,0);

        vector<vector<int>> ans;
        par[0] = -1;
        int time = 0;
        dfs(0,vis,par,disc,low,ans,adj,time);
        return ans;
    }
};
