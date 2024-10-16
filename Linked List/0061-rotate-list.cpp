class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // Agar list empty hai ya ek hi node hai, toh rotation ka koi faayda nahi
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* temp = head;
        ListNode* tail = nullptr;
        int n = 0;  // List ka size track karne ke liye

        // List ka size find karo aur simultaneously last node (tail) ko bhi point karo
        while(temp != nullptr){
            if(temp->next == nullptr) tail = temp;  // Tail ko last node pe point kar rahe hain
            temp = temp->next;
            n++;  // List ka size badhao
        }

        // k ko list ke size ke mod se reduce karo, taaki larger k handle ho sake
        k = k % n;
        if(k == 0) return head;  // Agar k 0 ho gaya toh koi rotation nahi karna

        temp = head;  // temp ko wapas head pe set karna zaroori hai, kyunki list ko traverse karna hai

        // n-k th node tak jao, jahan se list ko todna hai
        for(int i = 1; i < n-k; i++){
            temp = temp->next;        
        }

        // List ko circular bana rahe hain (tail ko head se jod rahe hain)
        tail->next = head;

        // New head banate hain aur temp ke next ko null karte hain to break the list
        head = temp->next;
        temp->next = nullptr;

        return head;  // Modified list return karo
    }
};
