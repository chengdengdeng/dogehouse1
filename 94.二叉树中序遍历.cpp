//94.二叉树中序遍历

//递归，经典
class Solution{
public:
	void inorder(TreeNode* root,vector<int>& res){
		if (!root){
			return;
		}
		inorder(root->left,res);
		res.push_back(root->val);
		inorder(root->right,res);
	}

	vector<int> inorderTraversal(TreeNode* root){
		vector<int> res;
		inorder(root,res);
		returun res;
	}
};

//迭代（栈）
class Solution{
public:
	vector<int> inorderTraversal(TreeNode* root){
		vector<int> res;
		stack<TreeNode*> stk;
		while(root != nullptr || !stk.empty()){
			while(root != nullptr){
				stk.push(root);
				root = root->left;
			}
			root = stk.pop();
			stk.pop();
			res.push_back(root->val);
			root = root->right;
		}
		return res;
	}
};

//Morris
class Solution{
public:
	vector<int> inorderTraversal(TreeNode* root){
		vector<int> res;
		TreeNode *predecessor = nullptr;

		while(root != nullptr){
			if(root->left != nullptr){
				predecessor = root->left;
				while(predecessor->right != nullptr && predecessor->right != root){
					predecessor = predecessor->right;
				}

				if(predecessor->right == nullptr){
					predecessor->right = root;
					root = root->left;
				}
				else{
					res.push_back(root->val);
					predecessor->right = nullptr;
					root = root->right;
				}
			}
			else{
				res.push_back(root->val);
				root = root-->right;
			}
		}
		return res;
	}
};
