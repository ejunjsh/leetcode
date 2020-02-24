class Solution {
public:
    int fib(int N) {
        if (N <= 1) {
            return N;
        }
        return memoize(N);
    }
    
    int memoize(int N) {
      vector<int> cache(N+1);
      cache[0] = 0;  
      cache[1] = 1;

      for (int i = 2; i <= N; i++) {
          cache[i] = cache[i-1] + cache[i-2];
      }
      return cache[N];
    }
};