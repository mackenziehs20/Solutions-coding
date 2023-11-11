class Graph {
private:
    vector<vector<pair<int, int>>> adj;
    vector<int> dis;
    vector<int> vis;
    int n;
public:
    
    Graph(int n, vector<vector<int>>& edges) {
        adj=vector<vector<pair<int, int>>>(n);
        this->n=n;
        for(vector<int>& edge: edges){
            adj[edge[0]].push_back({edge[1],edge[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0,node1});
        dis=vector<int>(n,INT_MAX);
        vis=vector<int>(n, 0);
        dis[node1]=0;
        while(!pq.empty()){
            int d=pq.top().first;
            int currNode=pq.top().second;
            pq.pop();
            vis[currNode]=1;
            for(auto& nhbr:adj[currNode]){
              if(vis[nhbr.first]==0 && dis[nhbr.first]>(dis[currNode]+nhbr.second)){
                dis[nhbr.first]=dis[currNode]+nhbr.second;
                pq.push({dis[nhbr.first],nhbr.first});
              }
            }
        }
        return dis[node2]==INT_MAX?-1:dis[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */