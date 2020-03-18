class Solution {
public:
    int countArrangement(int N) {
        vector<bool> visited(N+1);
        int count=0;
        calculate(N, 1, visited,count);
        return count;
    }
    
    void calculate(int N, int pos, vector<bool>& visited,int& count) {
        if (pos > N)
            count++;
        for (int i = 1; i <= N; i++) {
            if (!visited[i] && (pos % i == 0 || i % pos == 0)) {
                visited[i] = true;
                calculate(N, pos + 1, visited,count);
                visited[i] = false;
            }
        }
    }
};