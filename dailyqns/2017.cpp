using ll = long long;
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        ll n = grid[0].size();
        vector<ll>row1(n + 1,0),row2(n + 1,0);
        for(int i = 0;i <n;i++){
            row1[i + 1] = row1[i] + grid[0][i];
            row2[i + 1] = row2[i] + grid[1][i];
        }
        ll maxval = LLONG_MAX;
        for(int i = 1;i <= n;i++){
            ll val1 = row1[n] - row1[i],val2 = row2[i - 1];
            maxval = min(maxval,max(val1,val2));
        }
        return maxval;
    }
};