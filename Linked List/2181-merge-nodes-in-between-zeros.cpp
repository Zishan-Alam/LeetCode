class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        // Ek dummy node banate hain jo humare final result ko point karega
        ListNode* dummy = new ListNode(0);
        // Head ke next node se traversal start karte hain, kyunki head par 0 hota hai
        ListNode* curr = head->next;

        // Temp pointer jo dummy node ke saath result ko track karega
        ListNode* temp = dummy;

        // Sum variable jo nodes ka sum store karega jab tak 0 na mile
        int sum = 0;

        // List traverse karte hain jab tak current node null na ho jaye
        while (curr != nullptr) {
            // Agar current node ka value 0 nahi hai, to sum calculate karo
            if (curr->val != 0) {
                sum = sum + curr->val;
                curr = curr->next;  // Agli node par move karo
            }
            else {
                // Jab current node ka value 0 ho, to ab tak ka sum store karo
                temp->next = curr;  // Temp pointer ko current node (jisme 0 hai) se jodo
                curr->val = sum;  // Current node ka value sum ke equal set karo
                temp = curr;  // Temp pointer ko next result node par move karo
                curr = curr->next;  // Current ko agle node par move karo
                sum = 0;  // Sum ko reset karo agle group ke liye
            }
        }

        // Dummy node ke next se modified list return karo
        return dummy->next;
    }
};
