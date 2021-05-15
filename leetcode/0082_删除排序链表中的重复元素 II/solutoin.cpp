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
        if (!head) {
            return nullptr;
        }

        auto root = new ListNode(-1);
        root->next = head;
        auto pre = root;
        auto cur = pre->next;

        while (cur) {
            int curValue = cur->val;
            int count = 1;

            while (cur->next && cur->next->val == curValue) {
                cur = cur->next;
                count++;
            }
            if (count > 1) {
                pre->next = cur->next ? cur->next : nullptr;
            } else {
                pre = cur;
            }
            cur = cur->next ? cur->next : nullptr;
        }

        return root->next;
    }
};

int main() {
    Solution solution;
    vector<int> a{ 1,2,3,3,4,4,5 };
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