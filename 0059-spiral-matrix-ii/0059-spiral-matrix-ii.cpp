class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>answer(n,vector<int>(n,0));
        int starting_row=0;
        int ending_row = n-1;
        int starting_col=0;
        int ending_col=n-1;
        int total=n*n;
        int cnt=0;
       while(cnt<total)
        {
            for(int i = starting_col;i<=ending_col&&cnt<total;i++)
            {
                answer[starting_row][i]=cnt+1;
                cnt++;
               
            }
            starting_row++;
            for(int i = starting_row;i<=ending_row&&cnt<total;i++ )
            {
                answer[i][ending_col]=cnt+1;
                cnt++;
               
            }
            ending_col--;
            for(int i = ending_col;i>=starting_col&&cnt<total;i--)
            {
                answer[ending_row][i]=cnt+1;
                cnt++;
                
            }
            ending_row--;
            for(int i =  ending_row;i>=starting_row&&cnt<total;i--)
            {
                answer[i][starting_col]=cnt+1;
                cnt++;
               
            }
            starting_col++;
        
        }
   return answer;
    }
};