# Convex Polygon
 

Given a list of points that form a polygon when joined sequentially, find if this polygon is convex (Convex polygon definition).

Note:

* There are at least 3 and at most 10,000 points.
* Coordinates are in the range -10,000 to 10,000.
* You may assume the polygon formed by given points is always a simple polygon (Simple polygon definition). In other words, we ensure that exactly two edges intersect at each vertex, and that edges otherwise don't intersect each other.

Example 1:

    [[0,0],[0,1],[1,1],[1,0]]

Answer: True

Explanation:

![](https://leetcode.com/static/images/problemset/polygon_convex.png)

Example 2:

    [[0,0],[0,10],[10,10],[10,0],[5,5]]

Answer: False

Explanation:


 ![](https://leetcode.com/static/images/problemset/polygon_not_convex.png)