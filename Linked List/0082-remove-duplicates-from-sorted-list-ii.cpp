class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy;
        dummy->next = head;

        ListNode* temp = head;

        while(temp){
            if(temp->next != nullptr && temp->val == temp->next->val){
                // Jab tak duplicate nodes mil rahe hain, temp ko aage badhate jao.
                while(temp->next != nullptr && temp->val == temp->next->val){
                    temp = temp->next;
                }
                // Duplicates khatam hone ke baad, 'prev->next' ko next unique node pe point karwa do.
                //isse agar consecutive duplicates hai to tab tbhi reinitialize bhi hota ha, because prev ki value 
                //change sirf not equal to vale case mai hi ho rhi hai...
                prev->next = temp->next;
            }
            else{
                prev->next = temp;
                prev = temp;
            }
            // 'temp' ko aage badhao taaki traversal chalta rahe.
            temp = temp->next;
        }
        // Dummy node ke next ko return karte hain, jo updated list ka head hai.
        return dummy->next;
    }
};
