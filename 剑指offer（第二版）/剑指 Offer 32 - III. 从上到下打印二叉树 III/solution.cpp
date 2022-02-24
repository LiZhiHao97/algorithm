struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    vector<vector<int>> ans;
    stack<TreeNode*> stk;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);
        int layer = 1;

        while(!q.empty()) {
            int size = q.size();
            ans.push_back(vector<int> ());

            for (int j = 0; j < size; j++) {
                TreeNode* node = q.front();
                ans.back().push_back(node->val);
                if (layer & 1) {
                    if (node->left) stk.push(node->left);
                    if (node->right) stk.push(node->right);
                } else {
                    if (node->right) stk.push(node->right);
                    if (node->left) stk.push(node->left);
                }

                q.pop();
            }

            while(!stk.empty()) {
                q.push(stk.top());
                stk.pop();
            }

            layer++;
        }

        return ans;

    }
};