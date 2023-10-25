class Solution {
    private:
    int DFS(int n, int k, int val) {
        if(n == 1){
            return val;
        }

        int l = pow(2, n-1)/2;
        if(k <= l){
            int nextval = (val == 0) ? 0 : 1; 
            return DFS(n-1, k, nextval);
        }
        else{
            int nextval = (val == 0) ? 1 : 0;
            return DFS(n-1, k-l, nextval);
        }
    }
public:
    int kthGrammar(int n, int k) {
        return DFS(n , k  , 0);
        
    }
};