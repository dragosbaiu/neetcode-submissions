class Solution {
    vector<int> parent;
public:
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]); 
        return parent[x];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        parent.resize(edges.size()+1);
        iota(parent.begin(), parent.end(), 0); // parent[i] = i

        for (auto& e : edges) {
            int a = find(e[0]), b = find(e[1]);
            if (a == b) return e; 
            parent[a] = b; 
        }
        return {};
    }
};
