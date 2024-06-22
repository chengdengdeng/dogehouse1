// 530.二叉树的最小绝对差

class Solution{
public:
	void dfs(TreeNode* root,int& pre,int& ans){
		if (root == nullptr){
			return;
		}
		def(root->left,pre,ans);
		if (pre == -1){
			pre = root->val;
		} else{
			ans = min(ans,root->val - pre);
			pre = root->val;
		}
		dfs(root->rigiht,pre,ans);
	}

	int getMinimunDifference(TreeNode* root){
		int ans = INT_MAX,pre = -1;
		dfs(root,pre,ans);
		return ans;
	}
};