struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    unordered_map<int, int> inoder_index;
public:
    TreeNode* buildMyTree(
            const vector<int>& preorder,
            const vector<int>& inorder,
            int preorder_start,
            int preorder_end,
            int inorder_start,
            int inorder_end
    ) {
        if (preorder_start > preorder_end) {
            return nullptr;
        }

        int preorder_root = preorder[preorder_start];
        int inoder_root_index = inoder_index[preorder_root];
        int left_subtree_size = inoder_root_index - inorder_start;

        TreeNode* root = new TreeNode(preorder_root);

        root->left = buildMyTree(
                preorder,
                inorder,
                preorder_start + 1,
                preorder_start + left_subtree_size,
                inorder_start,
                inoder_root_index - 1
        );
        root->right = buildMyTree(
                preorder,
                inorder,
                preorder_start + left_subtree_size + 1,
                preorder_end,
                inoder_root_index + 1,
                inorder_end
        );

        return root;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();

        for (int i = 0; i < n; i++) {
            inoder_index[inorder[i]] = i;
        }

        return buildMyTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};