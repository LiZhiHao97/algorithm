class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (!n) {
            return 0;
        }

        int leftIdx = binarySearchLeft(nums, target);
        int rightIdx = binarySearchRight(nums, target);

        if (nums[leftIdx] == target && nums[rightIdx] == target) {
            return rightIdx - leftIdx + 1;
        }
        return 0;
    }

    int binarySearchLeft(vector<int> &nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    int binarySearchRight(vector<int> &nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2 + 1;
            if (nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        return l;
    }
};