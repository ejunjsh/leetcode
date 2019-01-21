class Solution{
    public:
        int maximalRectangle(vector<vector<char> > &matrix) {
            int res = 0;
            vector<int> height;
            for (int i = 0; i < matrix.size(); ++i) {
                height.resize(matrix[i].size());
                for (int j = 0; j < matrix[i].size(); ++j) {
                    height[j] = matrix[i][j] == '0' ? 0 : (1 + height[j]);
                }
                res = max(res, largestRectangleArea(height));
            }
            return res;
        }

    private:
        int largestRectangleArea(vector<int>& heights)
        {
            int maxRect = 0;
            stack<int> stack;
            for (unsigned i = 0; i <= heights.size(); )
            {
                if (stack.empty() || i < heights.size() && heights[i] >= heights[stack.top()])
                {
                    stack.push(i++);
                    continue;
                }

                const int currentHeight = heights[stack.top()];
                stack.pop();
                const int rect = currentHeight * (i - (stack.empty() ? -1 : stack.top()) - 1);
                if (rect > maxRect)
                {
                    maxRect = rect;
                }
            }

            return maxRect;
        }
};