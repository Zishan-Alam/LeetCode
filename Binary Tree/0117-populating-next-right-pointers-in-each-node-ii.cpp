//Constant Space
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
//DFS
class Solution {
public:

    Node* findNext(Node* node) {
        if(!node) return nullptr;
        return node->left? node->left : node->right;
    }

    void connectNodes(Node* node, Node* nextNode) {
        if(!node) return;
        node->next = nextNode;

        if(node->left) {
            node->left->next = node->right ? node->right : findNext(node->next);
        }
        if(node->right) {
            node->right->next = findNext(node->next);
        }

        connectNodes(node->right, findNext(node->next));
        connectNodes(node->left, node->right ? node->right : findNext(node->next));
    }

    Node* connect(Node* root) {
        if(!root) return root;

        connectNodes(root, nullptr);

        return root;
    }
};
