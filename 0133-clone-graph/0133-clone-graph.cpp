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

// Time Complexity: O(V + E).
// Space Complexity: O(V) 
class Solution {
private:
    // Hash map to keep track of already cloned nodes.
    // Key: Original Node pointer -> Value: Cloned Node pointer
    unordered_map<Node*, Node*> clonedNodes;

public:
    Node* cloneGraph(Node* node) {
        // Base Case 1: Empty graph 
        if (!node) 
            return NULL;

        // Base Case 2: If we have already visited and cloned this node,
        // simply return the cloned version to prevent infinite cycles.
        if (clonedNodes.find(node) != clonedNodes.end()) 
            return clonedNodes[node];

        // Step 1: Create a new deep copy of the current node.
        // We only copy the value for now; neighbors are handled next.
        Node* clone = new Node(node->val);

        // Step 2: Add it to the map IMMEDIATELY.
        // This is the most crucial step. We must register this node as "cloned" before we explore its neighbors, otherwise cyclic graphs will loop forever.
        clonedNodes[node] = clone;

        // Step 3: Iterate through all the neighbors of the original node.
        for (Node* neighbor : node->neighbors) {
            // Recursively call cloneGraph on each neighbor.
            // The recursive call will return the cloned neighbor, which we then
            // push into the new node's neighbors list.
            clone->neighbors.push_back(cloneGraph(neighbor));
        }

        // Step 4: Return the fully constructed cloned node.
        return clone;
    }
};