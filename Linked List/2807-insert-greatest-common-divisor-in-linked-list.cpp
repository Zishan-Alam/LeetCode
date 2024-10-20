//..............................................................Iterative Approach..................................................................................//

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* currNode = head;
        ListNode* nextNode = head->next;

        while(nextNode != nullptr){
            ListNode* newNode = new ListNode(__gcd(currNode->val, nextNode->val));

            currNode->next = newNode;
            newNode->next = nextNode;

            currNode = nextNode;
            nextNode = nextNode->next;
        }
        return head;
    }
};

//..............................................................Recursive Approach..................................................................................//

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* currNode = head;
        ListNode* nextNode = insertGreatestCommonDivisors(head->next);
        ListNode* newNode = new ListNode(__gcd(currNode->val, head->next->val));

        currNode->next = newNode;
        newNode->next = nextNode;

        return head;
    }
};



