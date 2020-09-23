class Solution {
public:
    string fractionAddition(string expression) {
        istringstream is(expression);
        int num = 0, dem = 0, A = 0, B = 1; 
        char c;
        while (is >> num >> c >> dem) {
            A = A * dem + num * B;
            B *= dem;
            int g = abs(gcd(A, B));
            A /= g;
            B /= g;
        }
        return to_string(A) + "/" + to_string(B);
    }
    
    int gcd(int a, int b) {
        return (b == 0) ? a : gcd(b, a % b);
    }
};