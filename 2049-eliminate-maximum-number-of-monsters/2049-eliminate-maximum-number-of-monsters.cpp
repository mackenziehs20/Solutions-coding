class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<double> time;
        int i;
        for(i=0;i<dist.size();i++)
        {
            time.push_back((double)dist[i]/(double)speed[i]);
        }
        sort(time.begin(),time.end());
        int t=0, max=0;
        for(auto a:time)
        {
            if(a>t)
           {
                t++;
                max++;
            }
            else
            break;
        }
        return max;
    }
};