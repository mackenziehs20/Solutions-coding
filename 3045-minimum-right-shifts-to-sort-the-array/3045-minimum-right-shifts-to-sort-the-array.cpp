class Solution {
public:
    /*
    * We need to find peak of the array.
    * everything uptil the peak should be in increasing order.
    * everything from the peak to end, should also be in increasing order
    * only then can we rotate. 
    * everything from the peak to the end, should also be lesser than peak, since 
    * after rotation, peak will become the last element of the array and hence 
    * has to be greatest.
    * if peak is not the first element, then everything from the peak to end should also
    * be lesser than 0th element, since after rotation, they will get to the head of the array.
    * if the above criteria is met, then number of shifts is from the peak to the 
    * end of the array.
    */
    int minimumRightShifts(vector<int>& nums) {
        bool is_peak = false;
        int max_pos = 0;
        for (int i=1;i<nums.size();i++) {
            if (nums[i] > nums[i-1]) {
                if (!is_peak)
                    max_pos = i;
                else if ((nums[max_pos] < nums[i]) || ((max_pos != 0) && (nums[0] < nums[i])))
                    return -1; 
            } else {
                if (is_peak)
                    return -1;
                is_peak = true;
            }
        }
        //printf("max_pos %d num %d \n", max_pos, nums[max_pos]);
        return nums.size()-1-max_pos;
    }
};