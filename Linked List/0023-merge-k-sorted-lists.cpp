class Solution {
public:

    ListNode* merge(ListNode* headA, ListNode* headB){

        ListNode* temp = new ListNode(0);
        ListNode* result = temp;  

        // Jab tak dono lists mein nodes hain, unhe compare karte hain
        while(headA != nullptr && headB != nullptr){
            if(headA->val <= headB->val){
                temp->next = headA;
                headA = headA->next;
                temp = temp->next;  // Temp pointer ko aage badhate hain
            }
            else{
                temp->next = headB;
                headB = headB->next;
                temp = temp->next;  // Temp pointer ko aage badhate hain
            }
        }

        // Agar headA ya headB bach gaya ho toh usko final merged list mein add kar do
        if(headA != nullptr) temp->next = headA;
        if(headB != nullptr) temp->next = headB;

        return result->next;  // Result ka next return karte hain, kyunki result->next actual merged list hai
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Agar list empty hai, toh null return karo
        if(lists.size() == 0) return nullptr;

        // Jab tak ek hi list nahi bachi, merge karte raho
        while(lists.size() > 1){
            ListNode* a = lists[0];  // Last list pick karo
            lists.erase(lists.begin());  // Last list ko hatao

            ListNode* b = lists[0];  // Ek aur last list pick karo
            lists.erase(lists.begin());  // Usse bhi hatao

            ListNode* c = merge(a, b);  // Dono lists ko merge karo
            lists.push_back(c);  // Merged result wapas list mein add karo
        }

        return lists[0]; // Final merged list return karo
    }
};
