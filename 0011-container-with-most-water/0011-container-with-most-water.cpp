class Solution {
public:
    int maxArea(vector<int>& height) {
       int res = 0;
       int left = 0;
       int right = height.size () - 1;
       while (left <= right)  {
            int h = min (height[left], height[right]);
            int w = right - left;
            res = max (res, h * w);
            if (height[left] < height[right])
                left++;
            else
                right--;
       }
       return res;
    }
};