class Solution {
public:
    int fib(int N) {
        double goldenRatio = (1 + sqrt(5)) / 2;
        return (int)round(pow(goldenRatio, N)/ sqrt(5));
    }
};