#include <iostream>
#include <vector>
#include <algorithm>

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
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *l = head;
        int n = 1;
        while(l->next) {
            n++;
            l = l->next;
        }
        int step = n - k % n;
        if (step == n) {
            return head;
        }

        l->next = head;

        while (step--) {
            l = l->next;
        }
        ListNode *ret = l->next;
        l->next = nullptr;

        return ret;
    }
};

int main() {
    Solution solution;
    vector<int> nums{};
    int k = 1;
    ListNode *head = new ListNode(-1);
    ListNode *l = head;

    for (int i = 0; i < nums.size(); i++) {
        l->next = new ListNode(nums[i]);
        l = l->next;
    }

    ListNode* ans = solution.rotateRight(head->next, k);

    while(ans) {
        cout << ans->val << endl;
        ans = ans->next;
    }

    return 0;
}