class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix_prod (nums.size () + 1, 1);
        vector<int> suffix_prod (nums.size () + 1, 1);
        for (int i = 1; i < nums.size (); i++) {
            prefix_prod[i] = prefix_prod[i - 1] * nums[i - 1];
        }

        for (int j = nums.size () - 2; j >= 0; j--) {
            suffix_prod[j] = suffix_prod[j + 1] * nums[j + 1];
        }
        vector<int> answer;
        for (int i =  0; i < nums.size (); i++) {
            answer.push_back (prefix_prod[i] * suffix_prod[i]);
        }
        return answer;
    }
};


// TLE
        // vector<int> answer (nums.size (), 1);
        // for (int i = 0; i < nums.size (); i++) {
        //     for (int j = 0; j < nums.size (); j++) {
        //         if (i == j)
        //             continue;
        //         answer[i] *= nums[j];
        //     }
        // }
        // return answer;