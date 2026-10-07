/* Node Structure
class Node {
	public:
	int data;
	Node* left, *right;
	Node(int val) {
		data = val;
		left = right = nullptr;
	}
}; */

class Solution {
	public:
	
	void transversalleft(Node* root, vector<int>&ans)
	{
		if (root == nullptr || root->left == nullptr && root->right == nullptr)
			return;
		
		ans.push_back(root->data);
		
		if (root->left != nullptr)
			transversalleft(root->left, ans);
		else
			transversalleft(root->right, ans);
		
	}
	
	void transversalleftleaf(Node* root, vector<int>&ans)
	{ if (root == nullptr)
	return;
	if (root->left == nullptr && root->right == nullptr){
		ans.push_back(root->data);
	    return;
	}
	
	transversalleftleaf(root->left, ans);
	transversalleftleaf(root->right, ans);
	
}
void transversalrightleaf(Node* root, vector<int>&ans)
{ if (root == nullptr)
return;
if (root->left == nullptr && root->right == nullptr)
	ans.push_back(root->data);

transversalrightleaf(root->left, ans);
transversalrightleaf(root->right, ans);

}
void transversalright(Node* root, vector<int>&ans)
{
	if (root == nullptr || root->left == nullptr && root->right == nullptr)
		return;
	
	if (root->right != nullptr)
		transversalright(root->right, ans);
	else
		transversalright(root->left, ans);
	
	ans.push_back(root->data);
	
}

vector<int> boundaryTraversal(Node *root) {
	// code here
	vector<int> ans;
	if (root == nullptr)
		return ans;
	
	ans.push_back(root->data);
	
	transversalleft(root->left, ans);
	transversalleftleaf(root->left, ans);
	
	transversalrightleaf(root->right, ans);
	transversalright(root->right, ans);
	return ans;
}
};
