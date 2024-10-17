class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // Do dummy nodes banate hain, ek low list ke liye aur ek high list ke liye
        ListNode* low = new ListNode(0);  // Low list head
        ListNode* high = new ListNode(0); // High list head

        // Pointers to traverse both low and high lists
        ListNode* tempLow = low;
        ListNode* tempHigh = high;

        // Temporary pointer to traverse the original list
        ListNode* temp = head;

        // Agar list empty hai ya sirf ek element hai, toh waise hi return kar do
        if(head == nullptr || head->next == nullptr) return head;

        // Traverse the entire list and partition it
        while(temp != nullptr) {
            // Agar current node ki value x se chhoti hai toh low list mein add karo
            if(temp->val < x) {
                tempLow->next = temp;
                tempLow = tempLow->next;
                temp = temp->next;  
            }
            // Agar current node ki value x ke barabar ya zyada hai toh high list mein add karo
            else {
                tempHigh->next = temp;
                tempHigh = tempHigh->next;
                temp = temp->next;
            }
        }

        // Low list ke end ko high list ke start se connect kar do
        tempLow->next = high->next;
        // High list ke end ko null set kar do taaki cycle na ho
        tempHigh->next = nullptr;

        // Low list ke next node ko return karo, kyunki low ek dummy node se start hoti hai
        return low->next;
    }
};
