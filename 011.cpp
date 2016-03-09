class Solution {
public:
    int maxArea(vector<int>& height) {
        size_t left = 0, right = height.size() - 1;
        int water = 0, max_water = 0;
        while(left < right) {
            water = (right - left) * ( height[left] < height[right] ? height[left] : height[right]);
            max_water = water > max_water ? water : max_water;
            if(height[left] < height[right])
                left++;
            else
                right--;
        }
        return max_water;
    }
};