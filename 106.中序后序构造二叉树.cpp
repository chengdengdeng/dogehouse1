// 106.中序后序构造二叉树

// 1.递归
class Solution{
	int post_idx;
	unordered_map<int,int> idx_map;
public:
	TreeNode* helper(int in_left,int in_right,vector<int>& inorder,vector<int>& postorder){
		if (in_left > in_right){
			return nullptr;
		}
		int root_val = postorder[post_idx];
		TreeNode* root = new TreeNode(root_val);

		int index = idx_map[root_val];
		post_idx--;
		root->right = helper(index + 1,in_right,inorder,postorder);
		root->left = helper(in_left,index - 1,inorder,postorder);
		return root;
	}

	TreeNode* buildTree(vector<int>& inorder,vector<int>& postorder){
		post_idx = (int)postorder.size() - 1;
		int idx = 0;
		for (auto& val : inorder) {
			idx_map[val] = idx++;
		}
		return helper(0,(int)inorder.size() - 1,inorder,postorder);
	}
};

// 2.迭代
class Solution{
public:
	TreeNode* buildTree(vector<int>& inorder,vector<int>& postorder){
		if(postorder.size() == 0){
			return nullptr;
		}
		auto root = new TreeNode(postorder[postorder.size() - 1]);
		auto s = stack<TreeNode*>();
		s.push(root);
		int inorderIndex = inorder.size() - 1;
		for (int i = int(postorder.size()) - 2; i >= 0; i--) {
			int postorderVal = postorder[i];
			auto node = s.top();
			if(node->val != inorder[inorderIndex]){
				node->right = new TreeNode(postorderVal);
				s.push(node->right);
			} else{
				while(!s.empty()&&s.top()->val == inorder[inorderIndex]){
					node = s.top();
					s.pop();
					inorderIndex--;
				}
				node->left = new TreeNode(postorderVal);
				s.push(node->left);
			}
		}
		return root;
	}
};