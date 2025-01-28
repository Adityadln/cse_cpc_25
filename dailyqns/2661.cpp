class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(),m = mat[0].size();
        vector<int>row_val(n*m),col_val(m*n);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                row_val[mat[i][j] - 1] = i,col_val[mat[i][j] - 1] = j;
            }
        }
        vector<int>row(n,m),col(m,n);
        for(int i = 0;i < arr.size();i++){
            int x = row_val[arr[i] - 1],y = col_val[arr[i] - 1];
            row[x]--,col[y]--;
            if(row[x] == 0 || col[y] == 0)return i;
        }
        return -1;
    }
};