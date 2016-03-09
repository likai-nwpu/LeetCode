class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int min_diff = 0x7FFFFFFF;
        int rst, temp;
        cout << min_diff;
        sort(nums.begin(), nums.end());
        size_t low, high;
        for(size_t i = 0; i < nums.size(); i++) {
            low = 0;
            high = nums.size() - 1;
            while(low < i && high > i) {
                temp = nums[i] + nums[low] + nums[high];
                if(abs(temp - target) < min_diff) {
                    min_diff = abs(temp - target);
                    rst = temp;
                }
                if(temp > target){
                        --high;
                }
                else if(temp < target){
                    ++low;
                }
                else {
                    goto stop_zero;
                }
            }
        }
        stop_zero : return rst;
    }
};
