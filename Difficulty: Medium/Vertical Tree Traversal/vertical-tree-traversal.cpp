/* Structure of binary tree node
class Node {
	public:
	int data;
	Node* left;
	Node* right;
	
	Node(int val) {
		data = val;
		left = right = nullptr;
	}
}; */

class Solution {
	public:
	vector<vector<int>> verticalOrder(Node *root) {
		// code here
		vector<vector<int>> ans;
		if (root == nullptr)
			return ans;
		
		map<int, map<int, vector<int>> > nodes;
		queue<pair<Node*, pair<int, int>> > q; // [node,vertical,level]
		
		q.push({root, {0, 0}});
		
		while (!q.empty())
			{
			int size = q.size();
			for (int i = 0; i<size; i++)
				{
				auto it = q.front();
				q.pop();
				
				Node* curr = it.first;
				int x = it.second.first;
				int y = it.second.second;
				
				nodes[x][y].push_back(curr->data);
				if (curr->left)
					q.push({curr->left, {x - 1, y + 1}});
				if (curr->right)
					q.push({curr->right, {x + 1, y + 1}});
			}
		}
		for (auto it:nodes)
			{
			vector<int>level;
			for (auto q:it.second)
				{
				level.insert(level.end(), q.second.begin(), q.second.end());
			}
			ans.push_back(level);
		}
		return ans;
	}
};
