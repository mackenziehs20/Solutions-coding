class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        unordered_map<int , int> mp;
        for(int i = 0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        vector<int> freq;
        for(auto x : mp){
            freq.push_back(x.second);
        }
        priority_queue<int> pq;
        for(auto c:freq){
            pq.push(c);
        }
        if(pq.size() == 1){
            return pq.top();
        }
        while(true){
            int high = pq.top();
            pq.pop();
            int low = pq.top();
            pq.pop();
            if(low == 0){
                return high;
            }
            high--;
            low--;
            pq.push(low);
            pq.push(high);
        }
    }
};