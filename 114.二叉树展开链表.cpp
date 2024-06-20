// 114.二叉树展开链表

class Solution{
public:
	void flatten(TreeNode* root){
		TreeNode *curr = root;
		while(curr != nullptr){
			if (curr->left != nullptr){
				auto next = curr->left;
				auto predecessor = next;
				while(predecessor->right != nullptr){
					predecessor = predecessor->right;
				}
				predecessor->right = curr->right;
				curr->left = nullptr;
				curr->right = next;
			}
			curr = curr->right;
		}
	}
};