class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>> adj;
        int n = adjacentPairs.size();
        unordered_map<int,int> mp;

        for(auto it: adjacentPairs){
            int a = it[0];
            int b = it[1];

            adj[a].push_back(b);
            adj[b].push_back(a);
            mp[a]++;
            mp[b]++;
        }

        int root;
        for(auto it: mp){    //This is to find out the Either end of the graph
            if(it.second == 1){
                root = it.first;
                break;
            }
        }

        vector<int> ans;
        unordered_map<int,bool> visited;

        queue<int> que;
        que.push(root);
        ans.push_back(root);
        visited[root] = true;

        while(!que.empty()){
            int node = que.front();
            que.pop();

            for(auto v: adj[node]){
                if(!visited[v]){
                    visited[v] = true;
                    que.push(v);
                    ans.push_back(v);
                }
            }
        }
        return ans;
    }
};