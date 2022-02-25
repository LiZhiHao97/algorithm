class Solution {
private:
    Node *pre, *head;
    void inorderTraversal(Node* cur) {
        if (cur == nullptr) {
            return;
        }

        inorderTraversal(cur->left);
        if (pre != nullptr) {
            pre->right = cur;
            cur->left = pre;
        } else {
            head = cur;
        }
        pre = cur;
        inorderTraversal(cur->right);
    }
public:
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }

        inorderTraversal(root);
        head->left = pre;
        pre->right = head;
        
        return head;
    }
};