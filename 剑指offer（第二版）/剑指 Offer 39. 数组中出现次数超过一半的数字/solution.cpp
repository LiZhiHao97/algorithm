class Solution {
private:
    bool checkMoreThanHalf(int num, vector<int>& nums) {
        int length = nums.size();
        int times = 0;

        for (int i = 0; i < length; i++) {
            if (nums[i] == num) {
                times++;
            }
        }

        return times * 2 > length;
    }
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int curNum = nums[0];
        int count = 1;
        
        for (int i = 1; i < n; i++) {
            if (count == 0) {
                curNum = nums[i];
                count = 1;
                continue;
            }
            if (curNum == nums[i]) {
                count++;
            } else {
                count--;
            }
        }
        
        return checkMoreThanHalf(curNum, nums) ? curNum : 0;
    }
};