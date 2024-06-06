// 380.O(1)时间插入、删除、获取元素

// 基本的模版
class RandomizedSet{
public:
	RandomizedSet(){
		srand((unsigned)time(NULL));
	}

	bool insert(int val){
		if (indices.count(val)){
			return false;
		}
		int index = nums.size();
		nums.emplace_back(val);
		indices[val] = index;
		return true;
	}

	bool remove(int val){
		if (!indices.count(val)){
			return false;
		}
		int index = indices[val];
		int last = nums.back();
		nums[index] = last;
		indices[last] = index;
		nums.pop_back();
		indices.erase(val);
		return true;
	}

	int getRandom(){
		int randomIndex = rand() % nums.size();
		return nums[randomIndex];
	}
private:
	vector<int> nums;
	unordered_map<int,int> indices;
}

