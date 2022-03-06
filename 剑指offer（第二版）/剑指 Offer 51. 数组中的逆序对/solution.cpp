class Solution {
public:
    int reversePairs(vector<int>& nums) {
        vector<int> tmp(nums.size());

        return mergeSort(tmp, nums, 0, nums.size() - 1);
    }

    int mergeSort(vector<int>& tmp, vector<int>& nums, int l, int r) {
        if (l >= r) {
            return 0;
        }

        int mid = (l + r) / 2;
        int count = mergeSort(tmp, nums, l, mid) + mergeSort(tmp, nums, mid + 1, r);

        int i = l, j = mid + 1, pos = l;
        while (i <= mid && j <= r) {
            if (nums[i] > nums[j]) {
                count += mid - i + 1;
                tmp[pos] = nums[j];
                j++;
            } else {
                tmp[pos] = nums[i];
                i++;
            }
            pos++;
        }
        for (int k = i; k <= mid; k++) {
            tmp[pos++] = nums[k];
        }
        for (int k = j; k <= r; k++) {
            tmp[pos++] = nums[k];
        }
        copy(tmp.begin() + l, tmp.begin() + r + 1, nums.begin() + l);
        return count;
    }
};