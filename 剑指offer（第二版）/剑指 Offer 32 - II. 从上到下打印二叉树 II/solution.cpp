class Solution {
private:
    vector<vector<int>> ans;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            ans.push_back(vector<int> ());

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                ans.back().push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                q.pop();
            }

        }

        return ans;

    }
};