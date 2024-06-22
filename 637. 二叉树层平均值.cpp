// 637，二叉树层平均值

// 1.深度优先
class Solution{
public:
	vector<double> averageOfLevels(TreeNode* root){
		auto counts = vector<int>();
		auto sums = vector<double>();
		dfs(root,0,counts,sums);
		auto averages = vector<double>();
		int size = sums.size();
		for (int i = 0; i < size; ++i) {
			averages.push_back(sums[i]/counts[i]);
		}
		return averages;
	}

	void dfs(TreeNode* root,int level,vector<int> &counts,vector<double> &sums){
		if (root == nullptr){
			return;
		}
		if (level < sums.size()){
			sums[level] += root->val;
			counts[level] += 1;
		} else{
			sums.push_back(1.0 * root->val);
			counts.push_back(1);
		}
		dfs(root->left,level + 1,counts,sums);
		dfs(root->right,level + 1,counts,sums);
	}
};

// 2.广度优先
class Solution{
public:
	vector<double> averageOfLevels(TreeNode* root){
		auto averages = vector<double>();
		auto q = queue<TreeNode*>();
		q.push(root);
		while(!q.empty()){
			double sum = 0;
			int size = q.size();
			for (int i = 0; i < size; ++i) {
				auto node = q.front();
				q.pop();
				sum += node->val;
				auto left = node->left,right = node->right;
				if(left != nullptr){
					q.push(left);
				}
				if(right != nullptr){
					q.push(right);
				}
			}
			averages.push_back(sum/size);
		}
		return averages;
	}
};