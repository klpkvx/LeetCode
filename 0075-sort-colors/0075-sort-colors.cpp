class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int, int> data;
        for (int i : nums)
            data[i]++;
        nums.clear ();
        for (auto &[elem, count] : data)
            while (count--)
                nums.push_back (elem);
    }
};