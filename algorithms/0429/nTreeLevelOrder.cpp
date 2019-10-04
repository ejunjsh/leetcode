/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) 
	{
        if (root == NULL) 
			return vector<vector<int>>(); // We could also "return {};" here thanks to C++11. 
        vector<vector<int>> res; // Define a vector of vector for storing values of nodes. Data type: int
        queue<Node*> q; // Define the queue. Data type : pointers that point to nodes
        q.push(root); // Push the root node
        while (!q.empty()) // Whenever the queue is not empty
        {
            int size = q.size(); // Store the size of queue, which is the number of nodes in the current level
            vector<int> curLevel; // Store the result per level. 
            for (int i = 0; i < size; i++) // For each node of the current level
            {
                Node* tmp = q.front(); // Get the first node from the queue
                q.pop(); // Pop this node since we no longer need it.
                curLevel.push_back(tmp -> val); // Store values of tmp nodes
                for (auto n : tmp -> children) // Push every child node of the tmp node back to the queue. FIFO(first in first out)
                     q.push(n); 
            }
            res.push_back(curLevel); // Store the current level values to res.
        }
        return res; 
    }
};