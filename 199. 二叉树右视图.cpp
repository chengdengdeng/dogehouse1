// 199.二叉树右视图

// 1.深度优先
class Solution{
public:
	vector<int> rightSideView(TreeNode* root){
		unordered_map<int,int> rightmostValueAtDepth;
		int max_depth = -1;

		stack<TreeNode*> nodeStack;
		stack<int> depthStack;
		nodeStack.push(root);
		depthStack.push(0);

		while(!nodeStack.empty()){
			TreeNode* node = nodeStack.top();
			nodeStack.pop();
			int depth = depthStack.top();
			depthStack.pop();

			if (node != NuULL){
				max_depth = max(max_depth,depth);
				if (rightmostValueAtDepth.find(depth) == rightmostValueAtDepth.end()){
					rightmostValueAtDepth[depth] = node->val;
				}

				nodeStack.push(node->left);
				nodeStack.push(node->right);
				depthStack.push(depth + 1);
				depthStack.push(depth + 1);
			}
		}
		vector<int> rightView;

		for(int depth = 0;depth <= max_depth;depth++){
			rightView.push_back(rightmostValueAtDepth[depth]);
		}
		return rightView;
	}
};