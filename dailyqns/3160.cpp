class Solution {
    public:
        vector<int> queryResults(int limit, vector<vector<int>>& queries) {
            vector<int> ans;
            unordered_map<int, int> color_mpp,node_color;
            int cnt = 0;
            for (auto it : queries) {
                int ball = it[0], color = it[1];
                if (node_color.find(ball) != node_color.end()) {
                    int curr_color = node_color[ball];
                    color_mpp[curr_color]--;
                    if (color_mpp[curr_color] == 0) {
                        cnt--;
                        color_mpp.erase(curr_color);
                    }
                }
                if (color_mpp.find(color) == color_mpp.end()) {
                    cnt++;
                    color_mpp[color] = 1;
                } else
                    color_mpp[color]++;
                node_color[ball] = color;
                ans.push_back(cnt);
            }
            return ans;
        }
    };