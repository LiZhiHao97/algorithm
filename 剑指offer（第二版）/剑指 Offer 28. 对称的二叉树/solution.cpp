class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root, root);
    }

    bool isSymmetric(TreeNode* node1, TreeNode* node2) {
        if (node1 == nullptr && node2 == nullptr) {
            return true;
        }

        if (node1 == nullptr || node2 == nullptr) {
            return false;
        }

        if (node1->val != node2->val) {
            return false;
        }

        return isSymmetric(node1->left, node2->right) && isSymmetric(node1->right, node2->left);
    }
};