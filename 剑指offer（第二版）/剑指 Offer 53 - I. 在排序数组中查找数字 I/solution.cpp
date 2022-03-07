class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (!n) {
            return 0;
        }
        int ans = 0;

        int leftIdx = binarySearch(0, n - 1, nums, target, true);
        int rightIdx = binarySearch(0, n - 1, nums, target, false) - 1;

        if (leftIdx <= rightIdx && nums[leftIdx] == target && nums[rightIdx] == target) {
            ans = rightIdx - leftIdx + 1;
        }
        return ans;
    }

    int binarySearch(int l, int r, vector<int> &nums, int target, bool isLeft) {
        while (l < r) {
            int mid = (l + r) / 2;
            if ((nums[mid] >= target && isLeft) || nums[mid] > target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};