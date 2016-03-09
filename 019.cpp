/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode* p = head, *q;
        while(p != nullptr) {
            p = p->next;
            length++;
        }
        if(n == length) {
            head = head->next;
            return head;
        }
        q = p = head;
        for(int i = 0; i < length - n; i++) {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        delete p;
        return head;
    }
};
