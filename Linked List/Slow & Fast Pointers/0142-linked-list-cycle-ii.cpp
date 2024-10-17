class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;  // Slow pointer ko head se initialize karte hain
        ListNode* fast = head;  // Fast pointer bhi head se initialize hota hai

        bool flag = false;  // Flag to check if cycle exists

        // Fast aur slow pointers ko move karte hain jab tak cycle detect na ho
        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;  // Fast pointer ko do steps aage badhao
            slow = slow->next;        // Slow pointer ko ek step aage badhao

            // Agar slow aur fast pointers milte hain, toh cycle hai
            if(slow == fast) {
                slow = head;  // Slow pointer ko head pe wapas le aao
                flag = true;  // Cycle detect ho gayi, flag ko true set karo
                break;        // Break out of the loop as cycle is detected
            }
        }

        // Agar cycle detect hui hai toh cycle ka starting point find karte hain
        if(flag == true) {
            // Jab tak slow aur fast pointers milte nahi, unko ek step aage badhate raho
            while(slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;  // Yahi wo node hai jahan cycle start hoti hai
        }
        else {
            // Agar cycle nahi hai toh nullptr return karo
            return nullptr;
        }
    }
};
