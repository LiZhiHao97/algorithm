
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }

        ListNode* head = new ListNode();
        ListNode* l = head;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val > l2->val) {
                l->next = new ListNode(l2->val);
                l2 = l2->next;
            } else {
                l->next = new ListNode(l1->val);
                l1 = l1->next;
            }
            l = l->next;
        }

        while (l1 != nullptr) {
            l->next = new ListNode(l1->val);
            l1 = l1->next;
            l = l->next;
        }

        while (l2 != nullptr) {
            l->next = new ListNode(l2->val);
            l2 = l2->next;
            l = l->next;
        }

        return head->next;
    }
};