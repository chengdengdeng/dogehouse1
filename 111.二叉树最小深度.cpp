//111.二叉树最小深度

//深度优先
class Solution{
public:
	int minDepth(TreeNode *root){
		if (root == nullptr){
			return 0;
		}

		if (root->left == nullptr && root->right == nullptr){
			return 1;
		}

		int min_depth = INT_MAX;
		if (root->left != nullptr){
			min_depth = min(minDepth(root->left),min_depth);
		}
		if (root->right != nullptr){
			min_depth = min(minDepth(root->right),min_depth);
		}

		return min_depth + 1;
	}
};

//广度优先（队列）
class Solution{
public:
	int minDepth(TreeNode *root){
		if(root == nullptr){
			return 0;
		}

		queue<pair<TreeNode *,int>> q;
		q.emplace(root,1);
		while(!q.empty()){
			TreeNode *node = q.front().first;
			int depth = q.front().second;
			q.pop();
			if(node->left == nullptr && node->right == nullptr){
				return depth;
			}
			if(node->left != nullptr){
				q.emplace(node->left,depth + 1);
			}
			if(node->right != nullptr){
				q.emplace(node->right,depth + 1);
			}
		}
		return 0;
	}
};
