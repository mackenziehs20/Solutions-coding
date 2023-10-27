class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int len = 0;
        
        for(int i = 0; i < s.length(); i++){

            int l = i, r = i;
            while(l >= 0 && r < s.length() && s[l] == s[r]){
                int length = r-l+1;
                if(len < length){
                    len = length;
                    ans = s.substr(l,len);
                }
                l--, r++;
            }
            
            l = i, r = i+1;
            while(l >= 0 && r < s.length() && s[l] == s[r]){
                int length = r-l+1;
                if(len < length){
                    len = length;
                    ans = s.substr(l,len);
                }
                l--, r++;
            }
        }
        return ans;
    }
};