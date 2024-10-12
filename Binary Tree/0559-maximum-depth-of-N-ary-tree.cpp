/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        // Base case: if the node is NULL, the depth is 0
        if (root == nullptr) {
            return 0;
        }

        int maxChildDepth = 0;

        // Recursively calculate the depth of each child
        for (auto it : root->children) {
            maxChildDepth = max(maxChildDepth, maxDepth(it));
        }

        // Return 1 (for the current node) plus the maximum depth of the children
        return maxChildDepth + 1;
    }
};
