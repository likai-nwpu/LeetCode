class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *rst = new ListNode(0), *tail, *p, *l;
        p = rst->next = head;
        tail = rst;
        int m_count = 0;
        while(p = p->next)
            m_count++;
        for(int i = m_count / k;i > 0; i--) {
            int j = k;
            l = tail;
            tail = tail->next;
            while(--j > 0) {
                p = tail->next;
                tail->next = p->next;
                p->next = l->next;
                l->next = p;
            }
        }
        return rst->next;
    }
};