class Solution {
public:
    int mod=1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,long>mp;
        sort(arr.begin(),arr.end());
        int ans=0;
        for(int i=0;i<n;i++){
            long ways=1;
            for(int j=0,val=arr[0];(long)val*val<=arr[i];val=arr[++j]){
                if(arr[i]%val!=0)continue;
                if(mp.count(arr[i]/val)){
                    ways=(ways+(mp[val]*mp[arr[i]/val]*(val*val==arr[i]?1:2)))%mod;
                }
            }
            mp[arr[i]]=ways;
            ans=(ans+ways)%mod;;
        }
        return ans;
    }
};