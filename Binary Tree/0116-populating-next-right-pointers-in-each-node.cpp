class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;

        queue<Node*> q;
        q.push(root); 

        while(!q.empty()) {
            Node* rightNode = nullptr;
            int n = q.size();

            while(n--) {
                Node* curr = q.front(); q.pop();
                curr->next = rightNode;
                rightNode = curr;

                if(curr->right) {
                    q.push(curr->right);
                    q.push(curr->left);
                }
            }
        }
        return root;
    }
};

//Space : O(n)
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;

        if(root->left) root->left->next = root->right;
        if(root->next && root->right) root->right->next = root->next->left;

        connect(root->left);
        connect(root->right);

        return root;
    }
};
