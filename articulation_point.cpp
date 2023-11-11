class Solution {
  public:
    void dfs(int node,vector<int> &vis,vector<int> &disc,vector<int> &low,vector<int> &par
    ,vector<int> &ap, vector<int>adj[],int &t){
        vis[node] = 1;
        disc[node] = low[node] = t;
        t++;
        int count = 0;
        
        
        for(auto i : adj[node]){
            if(par[node] == i) continue;
            
            else if(vis[i]){
                low[node] = min(low[node],disc[i]);
            }
            else{
                par[i] = node;
                count++;
                dfs(i,vis,disc,low,par,ap,adj,t);
                low[node] = min(low[node],low[i]);
                
                if(low[i] >= disc[node] && par[node] != -1){
                    ap[node] = 1;
                }
            }
        }
        if(par[node] == -1 && count > 1){
            ap[node] = 1;
        }
    }
    
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        
        vector<int> vis(V,0);
        vector<int> disc(V);
        vector<int> low(V);
        vector<int> par(V);
        vector<int> ap(V,0);
        int t = 0;
        
        vector<int> answer;
        
        par[0] = -1;
        
        dfs(0,vis,disc,low,par,ap,adj,t);
        
        for(int i = 0; i < V;i++){
            if(ap[i]) answer.push_back(i);
        }
        
        if(answer.size() == 0) return {-1};
        
        return answer;
    }
};
