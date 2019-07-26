# Line Reflection
 

Given n points on a 2D plane, find if there is such a line parallel to y-axis that reflect the given set of points.

Example 1:

Given points = [[1,1],[-1,1]], return true.

Example 2:

Given points = [[1,1],[-1,-1]], return false.

Follow up:

Could you do better than O(n2)?

Hint:

1. Find the smallest and largest x-value for all points.
2. If there is a line then it should be at y = (minX + maxX) / 2.
3. For each point, make sure that it has a reflected point in the opposite side.