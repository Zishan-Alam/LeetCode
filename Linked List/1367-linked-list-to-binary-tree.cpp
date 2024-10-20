class Solution {
public:

    // Yeh function check karta hai ki linked list ka current node, tree ke current node se match karta hai ya nahi.
    // Agar match karta hai, to aage ke nodes ko recursively check karta hai tree ke left aur right subtree mein.
    bool check(ListNode* head, TreeNode* root) {
        // Agar linked list ka current node null hai, iska matlab pura list match ho gaya, to return true.
        if (head == nullptr) return true;
        
        // Agar tree ka current node null hai aur abhi linked list match nahi hui, to return false.
        if (root == nullptr) return false;

        // Agar linked list ka current node aur tree ka current node ka value match nahi karta, to return false.
        if (head->val != root->val) return false;

        // Recursively check karo linked list ke next node ko tree ke left ya right child ke saath.
        return check(head->next, root->left) || check(head->next, root->right);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        // Agar tree ka root null hai, to linked list ka koi path possible nahi hai, to return false.
        if (root == nullptr) return false;
        
        // Recursively check karte hain ki ya to current tree node se list ka path match kare, 
        // ya tree ke left subtree aur right subtree mein check karo.
        return check(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};
