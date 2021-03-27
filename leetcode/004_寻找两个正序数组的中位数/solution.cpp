class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        auto it1 = nums1.begin();
        auto it2 = nums2.begin();
        double prev = 0, cur = 0;
        int len = nums1.size() + nums2.size();
        int half = ceil(len * 1.0 / 2);
        while (nums1.size() + nums2.size() >= half) {
            prev = cur;
            if (nums1.size() == 0) {
                cur = *it2;
                nums2.erase(it2);
            } else if (nums2.size() == 0) {
                cur = *it1;
                nums1.erase(it1);
            } else {
                if (*it1 > *it2) {
                    cur = *it2;
                    nums2.erase(it2);
                } else {
                    cur = *it1;
                    nums1.erase(it1);
                }
            }
        }
        if (len % 2) {
            return cur;
        } else {
            return (cur + prev) / 2;
        }
    }
};