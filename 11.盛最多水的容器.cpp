// 11.盛最多水的容器

//双指针，节省空间
class Solution{
public:
	int maxArea(vector<int>& height){
		int res = 0;
		int i = 0;
		int j = height.size() - 1;
		while(i < j){
			int area = (j-i) * min(height[i],height[j]);
			res = max(res,area);
			if (height[i] < height[j]){
				i++;
			} else{
				j--;
			}
		}
		return res;
	}
};