// 98. 验证二叉搜索树

// 1.递归
class Solution{
public:
	bool helper(TreeNode* root,long long lower,long long upper){
		if (root == nullptr){
			return true;
		}
		if (root->val <= lower || root->val >= upper){
			return false;
		}
		return helper(root->left,lower,root->val) && helper(root->right,root->val,upper);
	}

	bool isValidBST(TreeNode* root){
		return helper(root,LONG_MIN,LONG_MAX);
	}
};

// 2.中序遍历
class Solution{
public:
	bool isValidBST(TreeNode* root){
		stack<TreeNode*> stack;
		long long inorder = (long long)INT_MAX - 1;

		while(!stack.empty() || root != nullptr){
			while(root != nullptr){
				stack.push(root);
				root = root->left;
			}
			root = stack.top();
			stack.pop();
			if(root->val <= inorder){
				return false;
			}
			inorder = root->val;
			root = root->right;
		}
		return true;
	}
};