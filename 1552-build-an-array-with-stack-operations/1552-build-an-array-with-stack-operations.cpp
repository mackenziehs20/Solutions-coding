class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int m=target.size();
        int i=0;
        stack<int> s;
        vector<string> output;
        int j=1;
        while(i<m){
            s.push(j);
            output.push_back("Push");
            if(target[i]!=s.top()){
                s.pop();
                output.push_back("Pop");
                j++;
            }
            else{
                i++;
                j++;
            }
        }
        return output;
    }
};