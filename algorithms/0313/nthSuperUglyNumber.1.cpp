class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> res(n,0), cur(primes.size());
        res[0]=1;

        for(int i = 1; i < n; i++){
            res[i] = INT_MAX;
            for(int j = 0; j < primes.size(); j++){
                if (primes[j] * res[cur[j]] == res[i-1]) {
                    cur[j]++;
                }
                res[i] = min(res[i], primes[j]*res[cur[j]]);
            }
        }
        return res[n-1];
    }
};