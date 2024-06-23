// 230.二叉搜索树第k小

class Solution{
public:
	int kthSmallest(TreeNode* root,int k){
		this->k = k;
		dfs(root);
		return res;
	}
private:
	int res,k;
	void dfs(TreeNode* root){
		if (root == nullptr) return;
		dfs(root->left);
		if (k == 0) return;
		if (--k == 0) res = root->val;
		dfs(root->right);
	}
};