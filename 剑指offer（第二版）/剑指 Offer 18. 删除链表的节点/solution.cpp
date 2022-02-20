#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

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
    ListNode* deleteNode(ListNode* head, int val) {
        if (head == nullptr) {
            return head;
        }

        ListNode* cur = head;

        if (cur->val == val) {
            cur = cur->next;
            return cur;
        }

        while(cur->next != nullptr) {
            if (cur->next->val == val) {
                cur->next = cur->next->next;
                break;
            }
            cur = cur->next;
        }
        return head;
    }
};

int main() {
    Solution solution;

    vector<int> nums{4, 5, 1, 9};
    int val = 1;
    ListNode* head = new ListNode(nums[0]);
    ListNode* p = head;
    for (int i = 1; i < nums.size(); i++) {
        p->next = new ListNode(nums[i]);
        p = p->next;
    }

    ListNode* ans = solution.deleteNode(head, val);

    while(ans != nullptr) {
        cout << ans->val << endl;
        ans = ans->next;
    }

    return 0;
}