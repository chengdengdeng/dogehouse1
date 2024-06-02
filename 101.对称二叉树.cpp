//101.对称二叉树

//递归
class Solution{
public:
	bool check(TreeNode *p,TreeNode *q){
		if (!p && !q) return true;
		if (!p || !q) return false;
		return p->val == q->val && check(p->left,q->right) && check(p->right,q->left);
	}

	bool isSymmetric(TreeNode* root){
		return check(root,root);
	}
};

//迭代
class Solution{
public:
	bool check(TreeNode *u ,TreeNode *v){
		queue<TreeNode*> q;
		q.push(u);q.push(v);
		while(!q.empty()){
			u = q.front();q.pop();
			v = q.front();q.pop();
			if(!u && !v) continue;
			if(!u || !v) || (u->val != v->val) return false;

			q.push(u->left);
			q.push(v->right);

			q.push(u->right);
			q.push(v->left);
		}
		return true;
	}

	bool isSymmetric(TreeNode* root){
		return check(root,root);
	}
};
