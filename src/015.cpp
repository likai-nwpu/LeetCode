class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int temp;
        vector<vector<int>> rst;
        sort(nums.begin(), nums.end());
        size_t low = 0, high = nums.size() - 1;
        for(size_t i = 0; i < nums.size(); i++) {
            //一开始对i进行移动，去重复。
            if(nums[i] == nums[i + 1]) {
                if(i + 2 <nums.size() && nums[i + 2] == nums[i])
                    continue;
            }
            low = 0;
            high = nums.size() - 1;
            while(low < i && high > i) {
                int k = nums[i];
                temp = nums[i] + nums[low] + nums[high];
                if(temp == 0) {
                    rst.push_back({nums[low], nums[i], nums[high]});
                    low++;
                    high--;
                }
                else if(temp > 0){
                    //移动到下一个不相等的位置
                    int x = nums[high];
                    while(nums[--high] == x);
                }
                else {
                    //移动到下一个不相等的位置
                    int x = nums[low];
                    while(nums[++low] == x);
                }
            }
            if(nums[i] == 0)
                i++;
        }
        return rst;
    }
};