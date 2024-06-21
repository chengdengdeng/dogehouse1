// 173.二叉搜索迭代器

// 1.扁平处理
class BSTIterator{
private:
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
		return res;
	}

	vector<int> arr;
	int idx;
public:
	BSTIterator(TreeNode* root):idx(0),arr(inorderTraversal(root)) {}

	int next(){
		return arr[idx++];
	}
	bool hasNext(){
		return (idx < arr.size());
	}
};