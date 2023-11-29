vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dist(V,INT_MAX);
        dist[S] = 0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        pq.push({0,S});
        
        while(!pq.empty()){
            int node = pq.top().second;
            int d = pq.top().first;
            
            pq.pop();
            
            for(auto N : adj[node]){
                if(dist[N[0]] > N[1] + d){
                    dist[N[0]] = N[1] + d;
                    pq.push({dist[N[0]],N[0]});
                }
            }
        }
        
        return dist;
        // Code here
    }
