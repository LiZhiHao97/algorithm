struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        if (!head) {
            return {};
        }
        vector<int> ans = reversePrint(head->next);
        ans.push_back(head->val);
        return ans;
    }
};