class Solution {
public:
    string ans="";
    vector<bool>vis;
    string getPermutation(int n, int k) {
        //there will be (n-1)! permutations starting from 
        //every digit
        //so we will see only those permutations starting from
        //particular digit
        if(n==1)
        return "1";
        int a=fact(n-1);
        vis.resize(n+1,false);
        int digit;
        if(k>a)
        {
            if(k%a==0)
            {
                digit=k/a;
            }
            else 
            {
                digit=(k/a)+1;
            }
            k=k-(a*(digit-1));
        }
        else
        {
            digit=1;
        }
        vis[digit]=true;
        string temp="";
        temp.push_back(digit+'0');
        fun(n,k,temp);
        return ans;
    }
    void fun(int &n,int &k,string temp)
    {
        if(temp.length()==n)
        {
            k--;
            if(k==0)
            {
                ans=temp;
            }
            return;
        }
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==true)
            {
                continue;
            }
            else
            {
                char ch=i+'0';
                vis[i]=true;
                fun(n,k,temp+ch);
                vis[i]=false;
            }
        }
    }
    int fact(int n)
    {
        if(n==0 or n==1)
        {
            return n;
        }
        int ans=1;
        for(int i=1;i<=n;i++)
        {
            ans=ans*i;
        }
        return ans;
    }
};