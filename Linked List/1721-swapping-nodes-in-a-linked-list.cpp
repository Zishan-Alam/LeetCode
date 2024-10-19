class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {

        // Pointers to store the k-th node from the beginning and the k-th node from the end
        ListNode* temp1 = head;
        ListNode* temp2 = head;

        ListNode* temp = head;
        int length = 0;

        // First, calculate the total length of the linked list
        while(temp){
            temp = temp->next;
            length++;
        }

        // Reset temp to the head for next traversal
        temp = head;

        // Calculate the positions of the k-th node from the beginning and the end
        int firstIdx = k;
        int lastIdx = length-k+1;

        int n = 1;

        // Traverse the list again to find the k-th node from both the start and end
        while(temp){
            if(n == firstIdx) temp1 = temp;
            if(n == lastIdx) temp2 = temp;

            temp = temp->next;
            n++;
        }
        //swapping the values
        swap(temp1->val, temp2->val);

        return head;
        
    }
};
