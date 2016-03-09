class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        ListNode* first, *second, *pre;
        ListNode* l = new ListNode(0);
        l->next = head;

        pre = l;
        second = l->next;
        int m_count = 0;
        while(second != NULL) {
            m_count++;
            if(m_count > 2)
                pre = pre->next;
            if(m_count % 2 == 1) {
                //ºóÒÆ
                first = second;
                second = second->next;
            } else {
                //½»»»
                pre->next = second;
                first->next = second->next;
                second->next = first;

                second = first->next;
                first = pre->next->next;
            }
        }
        return l->next;
    }
};