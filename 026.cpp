class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1, temp;
        for(int i = 0, temp = nums[0]; i < nums.size(); i++) {
            if(temp == nums[i])
                continue;
            else{
                nums[count] = nums[i];
                count++;
                temp = nums[i];
            }
        }
        return nums.size() == 0 ? 0 : count;
    }
};