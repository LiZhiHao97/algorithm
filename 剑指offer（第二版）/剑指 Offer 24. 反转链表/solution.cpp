#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        if (head->next == nullptr) {
            return head;
        }

        ListNode* first = new ListNode();
        ListNode* pre = head;
        ListNode* cur = head->next;
        first->next = head;

        while (cur != nullptr) {
            pre->next = cur->next;
            cur->next = first->next;
            first->next = cur;
            cur = pre->next;
        }

        return first->next;
    }
};


int main() {
    Solution solution;

    vector<int> nums{1, 2, 3, 4, 5};
    ListNode* head = new ListNode();
    ListNode* p = head;

    for (int i = 0; i < nums.size(); i++) {
        p->next = new ListNode(nums[i]);
        p = p->next;
    }

    ListNode* ans = solution.reverseList(head->next);

    while (ans != nullptr) {
        cout << ans->val << endl;
        ans = ans->next;
    }

    return 0;
}