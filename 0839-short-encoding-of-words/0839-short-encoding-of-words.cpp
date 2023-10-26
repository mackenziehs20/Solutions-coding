class Solution 
{
class Trie
{
    struct node
    {
        int e{};
        node* m[26]{};
    } trie;
public:
    int out{};
    Trie() 
    {    
    }
    
    void insert(string w)
    {
        auto t = &trie;
		for(int i{}; i<size(w); ++i)
        {
            auto c = w[size(w)-1-i]; 
    		t = t->m[c-'a'] ? t->m[c-'a'] : t->m[c-'a']=new node{};
            
            if(t->e==-1) out-=i+2;
            if(i+1==size(w) and t->e<1) 
                out+=i+2, t->e=-1; 
            else
                t->e=1;
        }
    }
};
        
public:
    int minimumLengthEncoding(vector<string>& w)
    {
        Trie t;
        for(const auto & w : w)
            t.insert(w);
        return t.out;
    }
};