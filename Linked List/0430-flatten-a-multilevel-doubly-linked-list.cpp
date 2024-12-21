/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* temp = head; // List traverse karne ke liye pointer

        while (temp) {
            Node* a = temp->next; // Next node ko store karte hain
            if (temp->child != nullptr) { // Agar child list hai
                Node* c = temp->child;
                temp->child = nullptr; // Child pointer ko null karte hain
                c = flatten(c); // Recursively child list flatten karte hain
                temp->next = c;
                c->prev = temp;

                while (c->next != nullptr) { // Child list ke last tak jaate hain
                    c = c->next;
                }
                c->next = a;
                if (a) a->prev = c;
            }
            temp = a; // Next node par move karte hain
        }
        return head; // Flattened list ka head return karte hain
    }
};
