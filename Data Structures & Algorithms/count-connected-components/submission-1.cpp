class Solution {
    vector<bool> visited;
    unordered_map<int, vector<int>> adj;
public:
    void dfs(int node) {
        visited[node] = true;
        for (int next : adj[node])
            if (!visited[next])
                dfs(next);
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        int count = 0;
        visited.assign(n, false);

        for (const auto& edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                dfs(i);                   
            }
        }
        return count;
    }
};
