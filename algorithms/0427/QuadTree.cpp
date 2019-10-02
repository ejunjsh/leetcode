/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        return build(grid, 0, 0, grid.size() - 1, grid.size() - 1);
    }
    Node* build(vector<vector<int>>& grid, int r1, int c1, int r2, int c2) {
        if (r1 > r2 || c1 > c2) return NULL;
        bool isLeaf = true;
        int val = grid[r1][c1], rowMid = (r1 + r2) / 2, colMid = (c1 + c2) / 2;
        for (int i = r1; i <= r2; ++i) {
            for (int j = c1; j <= c2; ++j) {
                if (grid[i][j] != val) {
                    isLeaf = false;
                    break;
                }
            }
        }
        if (isLeaf) return new Node(val == 1, true, NULL, NULL, NULL, NULL);
        return new Node(false, false, 
               build(grid, r1, c1, rowMid, colMid),
               build(grid, r1, colMid + 1, rowMid, c2),
               build(grid, rowMid + 1, c1, r2, colMid),
               build(grid, rowMid + 1, colMid + 1, r2, c2));
    }
};