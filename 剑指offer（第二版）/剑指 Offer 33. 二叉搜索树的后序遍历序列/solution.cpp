class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        int n = postorder.size();

        return verifySubTree(postorder, 0, n - 1);
    }

    bool verifySubTree(vector<int>& postorder, int start, int end) {
        if (start >= end) return true;

        int root = postorder[end];

        int i = start;
        while (postorder[i] < root) i++;
        int j = i;
        while (postorder[j] > root) j++;

        return j == end && verifySubTree(postorder, start, i - 1) && verifySubTree(postorder, i, end - 1);
    }
};