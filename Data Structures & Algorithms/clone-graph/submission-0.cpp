/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;

        unordered_map<Node*, Node*> clone;
        queue <Node*> q;

        clone[node] = new Node(node->val);
        q.push(node);

        while (!q.empty()){
            Node* cur = q.front();
            q.pop();

            for (Node* nb : cur->neighbors) {
                if (clone.count(nb) == 0) {
                    clone[nb] = new Node(nb->val); 
                    q.push(nb);
                }

                clone[cur]->neighbors.push_back(clone[nb]); 
            }
        }
        return clone[node];
    }
};
