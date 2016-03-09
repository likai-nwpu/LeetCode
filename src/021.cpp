class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head, *p, *pt1 = l1, *pt2 = l2;
        //head
        head = p = new ListNode(0);
        while (pt1 != NULL && pt2 != NULL) {
            if(pt1->val < pt2->val) {
                p->next = pt1;
                pt1 = pt1->next;
            } else {
                p->next = pt2;
                pt2 = pt2->next;
            }
            p = p->next;
        }
        if(pt1 != nullptr)
            p->next = pt1;
        else
            p->next = pt2;
        return head->next;
    }
};