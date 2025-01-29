class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>&b) {
        int n = a.size(),pre = 0;
        vector<int>map1(n + 1,0),map2(n + 1,0),arr(n);
        for(int i = 0;i < n;i++){
            if(map2[a[i]] == 1)pre++;
            if(map1[b[i]] == 1)pre++;
            if(a[i] == b[i])pre++;
            arr[i] = pre;
            map1[a[i]] = 1,map2[b[i]] = 1;
        }
        return arr;
    }
};