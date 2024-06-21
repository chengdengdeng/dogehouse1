// 129.根到叶子结点数字之和

// 1.深度优先
class Solution{
public:
	int dfs(TreeNode* root,int prevSum){
		if (root == nullptr){
			return 0;
		}
		int sum = prevSum * 10 + root->val;
		if (root->left == nullptr && root->right == nullptr){
			return sum;
		} else{
			return dfs(root->left,sum) + dfs(root->right,sum);
		}
	}
	int sumNumbers(TreeNode* root){
		return dfs(root,0);
	}
};

// 2.广度优先
class Solution{
public:
	int sumNumbers(TreeNode* root){
		if(root == nullptr){
			return 0;
		}
		int sum = 0;
		queue<TreeNode*> nodeQueue;
		queue<int> numQueue;
		nodeQueue.push(root);
		numQueue.push(root->val);
		while(!nodeQueue.empty()){
			TreeNode* node = nodeQueue.front();
			int num = numQueue.front();
			nodeQueue.pop();
			numQueue.pop();
			TreeNode* left = node->left;
			TreeNode* right = node->right;
			if(left == nullptr && right == nullptr){
				sum += num;
			} else{
				if(left != nullptr){
					nodeQueue.push(left);
					numQueue.push(num*10 + left->val);
				}
				if(right != nullptr){
					nodeQueue.push(right);
					numQueue.push(num*10 + right->val);
				}
			}
		}
		return sum;
	}
};