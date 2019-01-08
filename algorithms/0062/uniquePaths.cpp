class Solution{
    public:
        int uniquePaths(int m,int n){
            if (m > n) return uniquePaths(n, m);
            vector<int> cur(m, 1);
            for (int j = 1; j < n; j++)
                for (int i = 1; i < m; i++)
                    cur[i] += cur[i - 1]; 
            return cur[m - 1];
        }
};