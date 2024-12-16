//Approach-01 : BFS (level by level)
//TC : time complexity of this algorithm is O(N)
//SC : space complexity is O(W), where W is the maximum width of the tree
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {

        if(!root) return {};
        queue<TreeNode*> que;
        que.push(root);

        vector<int> result;

        while(!que.empty()) {
            int n = que.size();
            int maxi = INT_MIN;

            while(n--) {
                TreeNode* node = que.front();
                que.pop();

                maxi = max(maxi, node->val);

                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);

            }
            result.push_back(maxi);
        }
        return result;
    }
};

//Approach-02 : DFS 
//TC : time complexity of the given solution is O(N)

//SC : space complexity is O(H), where H is the height of the binary tree. 
//This space is used for the recursion stack during the depth-first traversal. 
//In the worst case, for a skewed tree (where each node has only one child), 
//the height H can be equal to N, leading to a space complexity of O(N)
class Solution {
public:

    vector<int> result;

    void solve(TreeNode* root, int depth) {
        if(!root) return;

        if(result.size() == depth) {
            result.push_back(root->val);
        }
        else{
            result[depth] = max(result[depth], root->val);
        }

        solve(root->left, depth+1);
        solve(root->right, depth+1);
    }

    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};

        solve(root, 0);
        return result;
    } 
};
