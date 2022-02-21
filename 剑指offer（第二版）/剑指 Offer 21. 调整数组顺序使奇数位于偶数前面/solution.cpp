class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return nums;
        }

        int left = 0, right = n - 1;

        while (left < right) {
            while ((nums[left] & 1) && left < n - 1) {
                left++;
            }
            while (!(nums[right] & 1) && right > 0) {
                right--;
            }
            if (left < right) {
                int tmp = nums[left];
                nums[left] = nums[right];
                nums[right] = tmp;
            }
        }

        return nums;
    }
};