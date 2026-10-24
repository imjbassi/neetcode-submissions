class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] > nums[r])
                l = mid + 1;   // drop is to the right of mid
            else
                r = mid;       // mid could be the minimum, keep it
        }
        return nums[l];
    }
};