//108.有序数组转换为二叉搜索树

//将中点作为根节点，中点左侧作为左子树，右侧作为右子树
class Solution{
public:
	TreeNode sortedArrayToBST(int [] nums){
		if (nums.size() == 0){
			return nullptr;
		}
		int mid = nums.length/2;
		TreeNode root = new TreeNode(nums[mid]);
		root.left = sortedArrayToBST(Arrays.copyOfRange(nums,0,mid));
		root.right = sortedArrayToBST(Arrays.copyOfRange(nums,mid+1,nums,length));
		return root;
	}
};