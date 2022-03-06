struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    stack<ListNode*> stack1, stack2;
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        while (headA != nullptr) {
            stack1.push(headA);
            headA = headA->next;
        }

        while (headB != nullptr) {
            stack2.push(headB);
            headB = headB->next;
        }
        ListNode* node = nullptr;

        while (!stack1.empty() && !stack2.empty() && stack1.top() == stack2.top()) {
            node = stack1.top();
            stack1.pop();
            stack2.pop();
        }

        return node;
    }
};

//class Solution {
//public:
//    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//        ListNode* A = headA;
//        ListNode* B = headB;
//
//        while (A != B) {
//            A = A != nullptr ? A->next : headB;
//            B = B != nullptr ? B->next : headA;
//        }
//
//        return A;
//    }
//};