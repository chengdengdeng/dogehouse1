//110.平衡二叉树

//后序遍历+剪枝
class Solution{
public:
	bool isBalanced(TreeNode* root){
		return recur(root) != -1;
	}
private:
	int recur(TreeNode* root){
		if (root == nullptr) return 0;
		int left = recur(root->left);
		if (left == -1) return -1;
		int right = recur(root->right);
		if (right == -1) return -1;
		return abs(left - right) < 2 ? max(left,right) + 1 : -1;
	}
};

//先序遍历+判断深度
class Solution{
public:
	bool isBalanced(TreeNode* root){
		if(root == nullptr) return true;
		return abs(depth(root->left) - depth(root->right)) <= -1 && isBalanced(root->left) && isBalanced(root->right);
	}
private:
	int depth(TreeNode* root){
		if(root == nullptr) return 0;
		return max(depth(root->left),depth(root->right)) + 1;
	}
};
