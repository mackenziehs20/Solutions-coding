#define ll long long 
class Solution {
public:
    int racecar(int target) {
        queue<pair<int, pair<ll, ll>>> q;
        q.push({0, {0, 1}});
        set<pair<ll, ll>> vis;
        while(!q.empty()){
            int move = q.front().first;
            ll position = q.front().second.first;
            ll speed = q.front().second.second;
            q.pop();

            if(target == position) return move;

            if(vis.find({position, speed})!=vis.end()){
                continue;
            }
            else{
                vis.insert({position, speed});
                q.push({move+1, {position + speed, speed*2}});
                if((position + speed> target && speed > 0) || (position + speed < target && speed<0)){
                    if(speed>0) speed = -1;
                    else speed = 1;
                    q.push({move+1, {position, speed}});
                }
            }
        }
        return -1;
    }
};