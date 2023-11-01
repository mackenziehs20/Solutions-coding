class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int c= 1;
        int ca = nums.front();
        int du = 1;
        for (int i = 1; i<nums.size();i++){
            if (nums[i] != ca ) {
                ca = nums[i];
                nums[c] = nums[i];
                c ++;
                du = 1;
            } else if (du < 2) {
                nums[c] = nums[i];
                c ++;
                du ++;
            } else {
                du++;
            }
        }
        return c;
    }
};