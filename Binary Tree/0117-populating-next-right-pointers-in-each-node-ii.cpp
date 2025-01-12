class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        Node* head = root;

        while(head) {
            Node* temp = new Node(0);           //to keep track of the next level of node
            Node* curr = temp;                  //for connecting the nodes to the next

            while(head) {
                if(head->left) {
                    curr->next = head->left;
                    curr = curr->next;
                }
                if(head->right) {
                    curr->next = head->right;
                    curr = curr->next;
                }
                head = head->next;              //for current iteration
            }
            head = temp->next;                  //for next iteration
        }
        return root;
    }
};
