#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
    vector<int> ans;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);

        return ans;
    }

    void inorder(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
};

TreeNode* createTree(vector<int> list, int pos) {
    if (list[pos] == NULL) {
        return NULL;
    }

    TreeNode* root = new TreeNode(list[pos]);

    int lnode = pos + 1;
    int rnode = pos + 2;

    if (lnode > list.size() - 1) {
        root->left = NULL;
    } else {
        root->left = createTree(list, lnode);
    }

    if (rnode > list.size() - 1) {
        root->right = NULL;
    } else {
        root->right = createTree(list, rnode);
    }

    return root;
}


int main() {
    Solution solution;
    vector<int> a{1, NULL, 2, 3};

    TreeNode* root = createTree(a, 0);

    vector<int> ans = solution.inorderTraversal(root);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }

    return 0;
}