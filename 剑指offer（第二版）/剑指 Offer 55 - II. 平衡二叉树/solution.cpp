class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }

    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;

        int leftDeepth = dfs(root->left);
        if (leftDeepth == -1) return -1;
        int rightDeepth = dfs(root->right);
        if (rightDeepth == -1) return -1;

        return abs(leftDeepth - rightDeepth) < 2 ? max(leftDeepth, rightDeepth) + 1: -1;
    }
};