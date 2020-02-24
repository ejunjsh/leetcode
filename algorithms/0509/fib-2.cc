class Solution {
public:
    vector<int> cache=vector<int>(31,-1);
    
    int fib(int N) {
        if (N <= 1) {
            return N;
        }
        cache[0] = 0;
        cache[1] = 1;
        return memoize(N);
    }
    
    int memoize(int N) {
      if (cache[N] != -1) {
          return cache[N];
      }
      cache[N] = memoize(N-1) + memoize(N-2);
      return memoize(N);
    }
};