class Solution {
public:
    int maxArea(vector<int>& height) {
        // height[i] - height (y), i - width (x);
        int maxresult = 0;
        int left = 0;
        int right = height.size () - 1;
        while (left < right){
            int tmp_height = min (height[left], height[right]);
            int tmp_width = right - left;
            maxresult = max (maxresult, tmp_height * tmp_width);
            if (height[right] < height[left])
                right--;
            else
                left++;
        }
        return maxresult;
    }
};