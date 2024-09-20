class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_product = INT_MIN;
        int tmp = 1;
        for (int i = 0; i < nums.size (); i++) {
            tmp *= nums[i];
            max_product = max (max_product, tmp);
            if (tmp == 0)
                tmp = 1;
        }
        tmp = 1;
        for (int i = nums.size () - 1; i >= 0; i--) {
            tmp *= nums[i];
            max_product = max (max_product, tmp);
            if (tmp == 0)
                tmp = 1;
        }
        return max_product;
    }
};