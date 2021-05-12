#include <iostream>
#include <vector>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* h = head;
        int sum = 0;
        bool flag = false;
        while (l1 != NULL || l2 != NULL) {
            sum = 0;
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            if (flag) {
                sum ++;
            }
            h->next = new ListNode(sum % 10);
            h = h -> next;
            flag = sum >= 10? true:false;
        }
        if (flag) {
            h->next = new ListNode(1);
        }
        return head->next;
    }
};

int main() {
    Solution solution;
    int a[3] = { 2, 4, 3 };
    int b[3] = { 5, 6, 4 };

    ListNode* la = new ListNode(-1);
    ListNode* lb = new ListNode(-1);

    ListNode* hla = la;
    ListNode* hlb = lb;

    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
        hla->next = new ListNode(a[i]);
        hla = hla->next;
    }
    for (int i = 0; i < sizeof(b) / sizeof(b[0]); i++) {
        hlb->next = new ListNode(b[i]);
        hlb = hlb->next;
    }
    ListNode* result = solution.addTwoNumbers(la->next, lb->next);
    while(result != NULL) {
        cout << result->val << endl;
        result = result->next;
    }
    return 0;
}
