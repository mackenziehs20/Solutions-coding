class Solution {
public:
    long long mod = 1e9+7;
    int countHomogenous(string s) {
        set<string> resSet;
        long long count=s.length();
        long long rep=1;
        char lastChar = 'A';

        for(auto ch: s){
            if(lastChar==ch){
                rep++;
            }
            else{
                if(rep>1){
                    count+=(((rep-1)*rep)/2)%mod;
                }                
                rep=1;
            }
            lastChar=ch;
        }
        if(rep>1){
            count+=(((rep-1)*rep)/2)%mod;
        }

        return count%mod;

    }
};