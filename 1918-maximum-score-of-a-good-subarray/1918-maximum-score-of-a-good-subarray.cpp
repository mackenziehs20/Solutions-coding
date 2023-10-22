class Solution {
public:
       int maximumScore(vector<int>& nums, int k) {
        // Initialize variables to keep track of key values and the result.
        int i = k, j = k; // i and j are pointers to the left and right of the chosen element.
        int mini = nums[k]; // Initialize mini as the value at index k.
        int n = nums.size(); // Get the size of the input array.
        int res = nums[k]; // Initialize the result with the value at index k.

        // Iterate while one of the pointers is valid (i >= 0 or j < n).
        while (i >= 0 || j < n) {
            // Move the left pointer (i) to the left until a value less than mini is found.
            while (i >= 0 && nums[i] >= mini)
                i--;

            // Move the right pointer (j) to the right until a value less than mini is found.
            while (j < n && nums[j] >= mini)
                j++;

            // Calculate the potential score by multiplying the width and mini.
            int potentialScore = (j - i - 1) * mini;

            // Update the result with the maximum potential score found.
            res = max(res, potentialScore);

            // Determine the new mini value based on the comparison of nums[i] and nums[j].
            if (i >= 0 && j < n) {
                if (nums[i] > nums[j]) {
                    mini = nums[i]; // Choose the greater value as the new mini.
                } else {
                    mini = nums[j];
                }
            } else if (i >= 0) {
                mini = nums[i]; // If j is out of bounds, set mini to the value at i.
            } else if (j < n) {
                mini = nums[j]; // If i is out of bounds, set mini to the value at j.
            }
        }

        // Return the maximum score obtained.
        return res;
    }
};