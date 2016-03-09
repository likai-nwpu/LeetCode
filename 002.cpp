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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int carry = 0, remainder = 0;
		ListNode *header_l1 = l1, *header_l2 = l2, *header = NULL, *p = NULL;
		while (l1 != NULL || l2 != NULL) {
			header = l1 != NULL ? header_l1 : header_l2;
			p = l1 != NULL ? l1 : l2;
			int a1, a2;
			if (l1 == NULL)
				a1 = 0;
			else a1 = l1->val;
			if (l2 == NULL)
				a2 = 0;
			else a2 = l2->val;
			int sum = a1 + a2 + carry;
			remainder = sum % 10;
			carry = sum / 10;
			if (l1 != NULL) {
				l1->val = remainder;
				l1 = l1->next;
			}
			if (l2 != NULL) {
				l2->val = remainder;
				l2 = l2->next;
			}
		}
		if (carry != 0) {
			ListNode *temp = new ListNode(carry);
			p->next = temp;
		}
		return header;
	}
};