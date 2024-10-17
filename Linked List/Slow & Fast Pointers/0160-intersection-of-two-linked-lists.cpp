class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;  // Pehla pointer headA se
        ListNode* tempB = headB;  // Dusra pointer headB se

        int lenA = 0;  // List A ka length
        int lenB = 0;  // List B ka length

        // List A ka length calculate karo
        while(tempA) {
            lenA++;
            tempA = tempA->next;
        }

        // List B ka length calculate karo
        while(tempB) {
            lenB++;
            tempB = tempB->next;
        }

        // Pointers ko wapas initialize karo
        tempA = headA;
        tempB = headB;

        // Agar List A lambi hai, toh usko List B ke barabar pe le jao
        if(lenA > lenB) {
            for(int i = 1; i <= lenA - lenB; i++) {
                tempA = tempA->next;
            }
        }
        // Agar List B lambi hai, toh usko List A ke barabar pe le jao
        else {
            for(int i = 1; i <= lenB - lenA; i++) {
                tempB = tempB->next;
            }
        }

        // Ab dono pointers ko ek hi speed se aage badhao
        // Jab tak intersection node nahi milta ya list khatam nahi hoti
        while(tempA != nullptr && tempB != nullptr) {
            if(tempA == tempB) return tempA;  // Intersection node mil gaya
            tempA = tempA->next;
            tempB = tempB->next;
        }

        // Agar koi intersection nahi mila toh null return karo
        return nullptr;
    }
};
