vector <long long> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<long long> dist(V,INT_MAX);
        dist[S] = 0;
        
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
        
        pq.push({0,S});
        
        while(!pq.empty()){
            long long node = pq.top().second;
            long long d = pq.top().first;
            
            pq.pop();

            if(d > dist[node]) continue;
            
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
