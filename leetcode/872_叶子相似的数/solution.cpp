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
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> seq1, seq2;

        dfs(seq1, root1);
        dfs(seq2, root2);

        for (int i = 0; i < seq1.size(); i++) {
            cout << seq1[i] << endl;
        }

        return seq1 == seq2;
    }

    void dfs(vector<int>& seq, TreeNode* node) {
        if (node == NULL) {
            return;
        }
        if (node->left == NULL && node->right == NULL) {
            seq.push_back(node->val);
            return;
        }

        dfs(seq, node->left);
        dfs(seq ,node->right);
    }
};

TreeNode* createTree(vector<int> list, int pos) {
    if (list[pos] == NULL) {
        return NULL;
    }

    TreeNode* root = new TreeNode(list[pos]);

    int lnode = 2 * pos + 1;
    int rnode = 2 * pos + 2;

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
    vector<int> a{3, 5, 1, 6, 2, 9, 8, NULL, NULL, 7, 4};
    vector<int> b{3, 5, 1, 6, 7, 4, 2, NULL, NULL, NULL, NULL, NULL, NULL, 9, 8};

    TreeNode* root1 = createTree(a, 0);
    TreeNode* root2 = createTree(b, 0);

    bool ans = solution.leafSimilar(root1, root2);

    cout << ans << endl;

    return 0;
}