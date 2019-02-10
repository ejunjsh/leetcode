class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        if (numRows == 0) {
            return triangle;
        }
        
        triangle.push_back(vector<int>());
        triangle[0].push_back(1);
        
        for (int rowNum = 1; rowNum < numRows; rowNum++) {
            vector<int> row;
            vector<int> prevRow = triangle[rowNum-1];

            // The first row element is always 1.
            row.push_back(1);

            // Each triangle element (other than the first and last of each row)
            // is equal to the sum of the elements above-and-to-the-left and
            // above-and-to-the-right.
            for (int j = 1; j < rowNum; j++) {
                row.push_back(prevRow[j-1] + prevRow[j]);
            }

            // The last row element is always 1.
            row.push_back(1);

            triangle.push_back(row);
        }

        return triangle;
    }
};