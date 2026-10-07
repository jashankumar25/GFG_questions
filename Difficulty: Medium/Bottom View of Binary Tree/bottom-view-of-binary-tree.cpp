/*
Definition for Node
class Node {
	public:
	int data;
	Node* left;
	Node* right;
	
	Node(int val) {
		data = val;
		left = right = nullptr;
	}
};
*/

class Solution {
	public:
	vector<int> bottomView(Node *root) {
		// code here
		vector<int> ans;
		if (root == nullptr)
			return ans;
		// map<vertical_distance, map<level, node_data>>
		map<int, map<int, int> > nodes;
		queue<pair<Node*, pair<int, int>> > q;
		
		q.push({root, {0, 0}});
		
		while (!q.empty())
			{
			int size = q.size();
			for (int i = 0; i<size; i++)
				{
				auto it = q.front();
				q.pop();
				
				Node * curr = it.first;
				int x = it.second.first;  // Horizontal distance
                int y = it.second.second; // Level
				
				nodes[x][y] = curr->data;
				
				if (curr->left)
					q.push({curr->left, {x - 1, y + 1}});
				if (curr->right)
					q.push({curr->right, {x + 1, y + 1}});
				
			}
		}
		
		// Extraction using nested map:
          // p.first = vertical distance (x)
          // p.second = map of levels {y -> data}
          for (auto p : nodes) {
              // p.second.rbegin()->second gives the data of the deepest level (max y) for this vertical line
              ans.push_back(p.second.rbegin()->second);
          }
		return ans;
	}
};
