#include <iostream>
#include <vector>
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* pre = new ListNode(0);
        ListNode* ans = pre;
        pre->next = head;

        while(pre->next && pre->next->next) {
            ListNode* start = pre->next;
            ListNode* end = pre->next->next;
            pre->next = end;
            start->next = end->next;
            end->next = start;
            pre = start;
        }

        return ans->next;
    }
};

int main() {
    Solution solution;
    int a[4] = { 1, 2, 3, 4 };
    ListNode* head = new ListNode(-1);

    ListNode* l = head;

    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
        l->next = new ListNode(a[i]);
        l = l->next;
    }

    ListNode* ans = solution.swapPairs(head->next);

    while(ans != NULL) {
        cout << ans->val << endl;
        ans = ans->next;
    }

    return 0;
}
