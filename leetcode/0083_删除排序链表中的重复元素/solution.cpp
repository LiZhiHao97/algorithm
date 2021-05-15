#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        int cur = 101;
        ListNode* l = head;
        ListNode* pre;
        while (l) {
            if (l->val == cur) {
                pre->next = l->next;
            } else {
                cur = l->val;
                pre = l;
            }
            l = l->next;
        }

        return head;
    }
};

int main() {
    Solution solution;
    vector<int> a{ 1, 1, 2 };
    ListNode* root = new ListNode(-1);
    ListNode* l = root;

    for (int i = 0; i < a.size(); i++) {
        l->next = new ListNode(a[i]);
        l = l->next;
    }

    ListNode* ans = solution.deleteDuplicates(root->next);

    while(ans) {
        cout << ans->val << endl;
        ans = ans->next;
    }


    return 0;
}