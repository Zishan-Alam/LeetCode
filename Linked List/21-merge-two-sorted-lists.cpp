class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        // Dummy node to start the merged list
        ListNode* dummy = new ListNode(100);
        ListNode* temp = dummy; // Temp pointer to traverse the new list

        // Jab tak dono lists mein nodes hain, comparison karte raho
        while(list1 != nullptr && list2 != nullptr){
            if(list1->val <= list2->val){
                temp->next = list1;
                list1 = list1->next; // list1 ka node add karo
                temp = temp->next; //list1 aage karo
            }
            else if(list2->val < list1->val){
                temp->next = list2;
                list2 = list2->next; // list2 ka node add karo
                temp = temp->next; //list2 aage karo
            }
        }
        // Agar list1 khatam ho gayi, toh bachi hui list2 ko attach kar do
        if(list1 == nullptr) temp->next = list2;
        // Agar list2 khatam ho gayi, toh bachi hui list1 ko attach kar do
        if(list2 == nullptr) temp->next = list1;

        return dummy->next; // Dummy node ka next return karo (actual merged list)
    }
};
