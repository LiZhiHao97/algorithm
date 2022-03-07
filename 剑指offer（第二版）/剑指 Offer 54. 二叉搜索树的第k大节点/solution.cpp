class Solution {
private:
    int ans, k;
public:
    int kthLargest(TreeNode* root, int k) {
        this->k = k;
        dfs(root);
        return ans;
    }

    void dfs(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        dfs(root->right);
        if (k == 0) return;
        if (--k == 0) {
            ans = root->val;
            return;
        }
        dfs(root->left);
    }
};