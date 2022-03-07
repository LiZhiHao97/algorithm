class Solution {
private:
    queue<TreeNode*> q;
    int count = 0;
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        bfs(root);
        return count;
    }

    void bfs(TreeNode* root) {
        q.push(root);

        while (!q.empty()) {
            int curSize = q.size();

            for (int i = 0; i < curSize; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            count++;
        }
    }
};