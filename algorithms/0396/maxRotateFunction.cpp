
// example:

// F(0) = 0A + 1B + 2C +3D

// F(1) = 0D + 1A + 2B +3C

// F(2) = 0C + 1D + 2A +3B

// F(3) = 0B + 1C + 2D +3A

// assume:

// sum = 1A + 1B + 1C + 1D

// F(1) = F(0) + sum - 4D

// F(2) = F(1) + sum - 4C

// F(3) = F(2) + sum - 4B

// then

// F(i) = F(i-1) + sum - n*A[n-i]

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        long t = 0, sum = 0, n = A.size();
        for (int i = 0; i < n; ++i) {
            sum += A[i];
            t += i * A[i];
        }
        long res = t;
        for (int i = 1; i < n; ++i) {
            t = t + sum - n * A[n - i];
            res = max(res, t);
        }
        return res;
    }
};