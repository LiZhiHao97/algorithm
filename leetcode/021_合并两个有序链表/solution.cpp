#include <iostream>
#include <stack>
#include <map>

using namespace  std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(-1);
        ListNode* ansH = ans;

        ListNode* a = l1;
        ListNode* b = l2;

        while(a && b) {
            if (a->val < b->val) {
                ansH->next = new ListNode(a->val);
                ansH = ansH->next;
                a = a->next;
            } else {
                ansH->next = new ListNode(b->val);
                ansH = ansH->next;
                b = b->next;
            }
        }
        ansH->next = a ? a : b;
        return ans->next;
    }
};

int main() {
    Solution solution;
    int a[4] = { 1, 2, 4, 5 };
    int b[3] = { 1, 3, 4 };
    ListNode* hl1 = new ListNode(-1);
    ListNode* hl2 = new ListNode(-1);

    ListNode* l1 = hl1;
    ListNode* l2 = hl2;

    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
        l1->next = new ListNode(a[i]);
        l1 = l1->next;
    }

    for (int i = 0; i < sizeof(b) / sizeof(b[0]); i++) {
        l2 -> next = new ListNode(b[i]);
        l2 = l2->next;
    }

    ListNode* ans = solution.mergeTwoLists(hl1->next, hl2->next);

    while(ans != NULL) {
        cout << ans->val << endl;
        ans = ans->next;
    }

    return 0;
}
