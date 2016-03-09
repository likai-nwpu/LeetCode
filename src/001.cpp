class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i+1; j < nums.size(); j++)
            {
                if(target == nums[i] + nums[j])
                {
                    vector<int> index;
                    index.push_back(i+1);
                    index.push_back(j+1);
                    return index;
                }
            }
        }
    }
};