class Solution {
    unordered_map<int, vector<int>> adj;
    vector<bool> visited;
public:

    bool dfs(int node, int parent) {
        visited[node] = true;
        for (int next : adj[node]) {
            if (next == parent) continue;          
            if (visited[next]) return false;       
            if (!dfs(next, node)) return false;
        }
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;


        for (const auto& edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        visited.assign(n, false);
        if (!dfs(0, -1)) return false;

        for (int i = 0; i < n; i++) 
            if (!visited[i]) return false;
        return true;
    }
};
