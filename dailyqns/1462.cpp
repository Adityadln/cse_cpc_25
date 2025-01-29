class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prereq, vector<vector<int>>& queries) {
        vector<vector<int>>adj(numCourses);
        vector<unordered_set<int>>se(numCourses);
        vector<int>in_degree(numCourses,0);
        for(auto it:prereq){
            adj[it[0]].push_back(it[1]);
            in_degree[it[1]]++;
        }
        queue<int>q;
        for(int i = 0;i < numCourses;i++){
            if(in_degree[i] == 0)q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cout<<node<<endl;
            for(auto adjnode : adj[node]){
                se[adjnode].insert(se[node].begin(),se[node].end());
                se[adjnode].insert(node);
                in_degree[adjnode]--;
                if(in_degree[adjnode] == 0)q.push(adjnode);
            }
        }
        int len = queries.size();
        vector<bool>ans(len,false);
        for(int i = 0;i < len;i++){
            int v = queries[i][1],u = queries[i][0];
            if(se[v].find(u) != se[v].end())ans[i] = true;
        }
        return ans;
    }
};