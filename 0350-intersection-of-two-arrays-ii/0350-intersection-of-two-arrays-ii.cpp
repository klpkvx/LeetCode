class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> n1_info; // nums[i] -> count;
        unordered_map<int, int> n2_info; // nums[i] -> count;
        unordered_map<int, int> result;
        for (auto val : nums1)
            n1_info[val]++;
        for (auto val : nums2)
            n2_info[val]++;

        const auto &curr_data = n1_info.size () < n2_info.size () ? n1_info : n2_info;
        const auto &cmp_data = n1_info.size () < n2_info.size () ? n2_info : n1_info;
        for (auto &[value, count] : curr_data){
            auto it = cmp_data.find (value);
            if (it != cmp_data.end ()){
                result[value] = min (count, it->second);
            }
        }

        vector<int> result_arr;
        for (auto &[value, count] : result){
            while (count--){
                result_arr.push_back (value);
            }
        }
        return result_arr;        
    }
};