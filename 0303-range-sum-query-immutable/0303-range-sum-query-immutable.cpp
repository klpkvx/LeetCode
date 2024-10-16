class NumArray {
public:
    NumArray(vector<int>& nums) {
        pref_sum = vector<int> (nums.size () + 1, 0);
        for (int i = 1; i < pref_sum.size (); i++) {
            pref_sum[i] = pref_sum[i - 1] + nums[i - 1];
        }
    }
    
    int sumRange(int left, int right) {
        right++;
        return pref_sum[right] - pref_sum[left];
    }
private:
    vector<int> pref_sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */