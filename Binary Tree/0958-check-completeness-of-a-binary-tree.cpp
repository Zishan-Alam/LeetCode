class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);

        bool isNull = false;

        while(!que.empty()) {
            int n = que.size();

            while(n--) {
                TreeNode* temp = que.front();
                que.pop();

                if(temp == nullptr) {
                    isNull = true;
                }
                else{
                    if(isNull == true) {
                        return false;
                    }
                    que.push(temp->left);       //idhar temp push karte hai, root nahi
                    que.push(temp->right);
                }
            }
        }
        return true;
    }
};
