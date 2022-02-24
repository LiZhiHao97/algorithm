class Solution {
private:
    vector<vector<int>> ans;
    vector<int> path;
public:
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        backtrace(root, target);

        return ans;
    }

    void backtrace(TreeNode* root, int target) {
        if (root == nullptr) {
            return;
        }
        path.push_back(root->val);
        target -= root->val;

        if (target == 0 && root->left == nullptr && root->right == nullptr) {
            ans.push_back(path);
        }

        backtrace(root->left, target);
        backtrace(root->right, target);
        
        path.pop_back();
    }
};