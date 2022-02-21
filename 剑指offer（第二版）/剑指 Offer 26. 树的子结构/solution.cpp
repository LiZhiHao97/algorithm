class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == nullptr || B == nullptr) {
            return false;
        }

        return hasSubTree(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }

    bool hasSubTree(TreeNode* A, TreeNode* B) {
        if (B == nullptr) {
            return true;
        }
        
        if (A == nullptr) {
            return false;
        }

        if (A->val != B->val) {
            return false;
        }

        return hasSubTree(A->left, B->left) && hasSubTree(A->right, B->right);
    }
};