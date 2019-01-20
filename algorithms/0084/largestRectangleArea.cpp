class Solution{
    public:
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