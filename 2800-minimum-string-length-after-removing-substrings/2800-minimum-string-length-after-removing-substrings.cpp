class Solution {
public:
    int minLength(string s) {
        stack<char>str;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(str.empty())
            str.push(ch);
            else if(ch=='B' && str.top()=='A')
            str.pop();
            else if(ch=='D' && str.top()=='C')
            str.pop();
            else
            str.push(ch);

        }
        return str.size();
    }
};














        // stack<char> s;
        // for(int i=0;i<str.length();i++)
        // {
        //     char ch = str[i];
        //     if(s.empty())
        //     s.push(ch);
        //     else if(ch == 'B' && s.top() == 'A')
        //     s.pop();
        //     else if(ch == 'D' && s.top() == 'C')
        //     s.pop();
        //     else 
        //     s.push(ch);
        // }
        // int ans = s.size();
        // return ans;
