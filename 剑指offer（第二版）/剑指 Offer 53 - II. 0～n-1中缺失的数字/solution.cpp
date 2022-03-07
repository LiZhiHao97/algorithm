class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int idx = binarySearch(nums);
        return idx == nums[idx] ? idx + 1: idx;
    }

    int binarySearch(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] != mid) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};