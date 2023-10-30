class Solution {
public:
    int count_bits(int n){
        
        // Initialising a variable to count the total.
        int total = 0;
        
        while (n){
            
            // If the last bit is 1, increment the total
            if((n&1)>0){
                ++total;
            }

            // Right shift the value of n
            n >>= 1;
        }
        return total;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> res;
        map<int, multiset<int>> mp;

        for(int i=0; i<arr.size(); i++){
            mp[count_bits(arr[i])].insert(arr[i]);
        }

        for(auto it: mp){
            multiset<int>::iterator itr;
   
            // Displaying set elements
            for (itr = it.second.begin(); 
                itr != it.second.end(); itr++) 
            {
                res.push_back(*itr);
            }
            
        }

        return res;
    }
};