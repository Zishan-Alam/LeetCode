class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        // Dummy nodes for even and odd lists
        ListNode* evenList = new ListNode(0);  // Even nodes ke liye
        ListNode* oddList = new ListNode(0);   // Odd nodes ke liye

        // Temporary pointers to traverse the even and odd lists
        ListNode* tempEven = evenList;
        ListNode* tempOdd = oddList;

        // Pointer to traverse the original list
        ListNode* temp = head;

        bool isOdd = true;  // Yeh boolean track karega ki abhi odd position pe hain ya even pe

        // Agar list empty hai ya sirf ek element hai toh return as is
        if(head == nullptr || head->next == nullptr) return head;

        // List ko traverse karte hain aur odd-even lists ko separate karte hain
        while(temp != nullptr) {
            if(isOdd) {
                // Odd position node ko odd list mein daalo
                tempOdd->next = temp;
                temp = temp->next;
                tempOdd = tempOdd->next;
                isOdd = !isOdd;  // Odd se even pe switch karo
            } else {
                // Even position node ko even list mein daalo
                tempEven->next = temp;
                temp = temp->next;
                tempEven = tempEven->next;
                isOdd = !isOdd;  // Even se odd pe switch karo
            }
        }

        // Odd list ke end ko even list ke start se connect karo
        tempOdd->next = evenList->next;
        // Even list ke end ko null kar do taaki cycle na bane
        tempEven->next = nullptr;

        // Odd list ke start (oddList->next) ko return karo, kyunki oddList ek dummy node hai
        return oddList->next;
    }
};
