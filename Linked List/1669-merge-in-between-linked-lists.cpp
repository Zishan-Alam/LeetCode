class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {

        // pointers to traverse both lists
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        ListNode* temp = list1;
        int n = 0;

        // Pehle list1 ko traverse karte hain taaki a-1 aur b+1 wale nodes ko find kar sakein
        while (temp != nullptr) {
            // Jab n a-1th index pe ho toh temp1 ko set karo
            if (n == a - 1) temp1 = temp;
            // Jab n b+1th index pe ho toh temp2 ko set karo
            if (n == b + 1) temp2 = temp;

            // Traverse to the next node and increment the index
            temp = temp->next;
            n++;
        }

        // temp ko list2 ka head bana rahe hain
        temp = list2;

        // temp1 ke next ko list2 ke head se link kar rahe hain (a-1th node ko list2 ke start se jodna)
        temp1->next = list2;

        // Ab list2 ke end tak traverse karo taaki list2 ke last node ko find kar sakein
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        // List2 ke end ko list1 ke b+1th node se link kar do
        temp->next = temp2;

        // Merged list return karo
        return list1;
    }
};
