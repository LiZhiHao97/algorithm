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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* pre = head;
        ListNode* cur = head;

        while(k-- && cur != nullptr) {
            cur = cur->next;
        }

        while(cur != nullptr) {
            cur = cur->next;
            pre = pre->next;
        }

        return pre;
    }
};


int main() {
    Solution solution;

    vector<int> nums{1, 2, 3, 4, 5};
    int k = 2;
    ListNode* head = new ListNode();
    ListNode* p = head;

    for (int i = 0; i < nums.size(); i++) {
        p->next = new ListNode(nums[i]);
        p = p->next;
    }

    ListNode* ans = solution.getKthFromEnd(head->next, k);

    while (ans != nullptr) {
        cout << ans->val << endl;
        ans = ans->next;
    }

    return 0;
}