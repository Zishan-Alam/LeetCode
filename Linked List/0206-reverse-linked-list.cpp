//ITERATIVE APPROACH
//Time Complexity = 0(n), Space Complexity = 0(1)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* aage = nullptr;

        while(curr != nullptr){
            aage = curr->next;
            curr->next = prev;
            prev = curr;
            curr = aage;
        }
        return prev;
    }
};

//*******************************************************************************************************************************************************************//

//RECURSIVE APPROACH 
//Time Complexity = 0(n), Space Complexity = stack space
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
      if(head == nullptr || head->next == nullptr) return head;

      ListNode* newHead = reverseList(head->next);

      head->next->next = head;
      head->next = nullptr;
      return newHead
    }






