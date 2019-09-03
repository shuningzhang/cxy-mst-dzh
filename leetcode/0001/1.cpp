class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        map<int, int> m;
        map<int, int>::iterator map_it;
        map<int, int>::iterator item;
        
        for(int i=0; i<nums.size(); i++) {
            //查找是否有满足条件的元素
            item = m.find(target - nums[i]); 
            //如果找到了该元素，将索引添加到数组，并退出循环 
            if (item != m.end()) {
                ret.push_back(item->second);
                ret.push_back(i);
                break;
            }
            //没有找到的情况下插入该元素
            m.insert(pair(nums[i], i));
        }       
        return ret;
    }
};
