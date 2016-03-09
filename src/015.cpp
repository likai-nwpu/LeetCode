class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int temp;
        vector<vector<int>> rst;
        sort(nums.begin(), nums.end());
        size_t low = 0, high = nums.size() - 1;
        for(size_t i = 0; i < nums.size(); i++) {
            //һ��ʼ��i�����ƶ���ȥ�ظ���
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
                    //�ƶ�����һ������ȵ�λ��
                    int x = nums[high];
                    while(nums[--high] == x);
                }
                else {
                    //�ƶ�����һ������ȵ�λ��
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