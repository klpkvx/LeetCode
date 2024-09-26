class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int totalsum = accumulate(nums.begin(),nums.end(),0);
        int target = totalsum - x;  //we have to remove x from either end total , we are left with subarray of sum target
        unordered_map<int,int> mp; //store prefix sums , for finding subarray with sum target
        mp[0] = -1;         //for subarrays starting from 0 index
        int presum = 0;
        int maxsub = INT_MIN;
        if(x == totalsum){
            return n;
        }
        for(int i=0;i<nums.size();i++){     //prefixsum algo mp: {prefixsum,index}
            presum += nums[i];
            if(mp.find(presum-target) != mp.end()){
                int sub = i - mp[presum-target];     //we have to maximise this , so minimum operations return
                maxsub = max(maxsub,sub);
            }
            mp[presum] = i;         //store prefisum with ending index
        }
        if(maxsub == INT_MIN){         //no subarray sum target recognised , return -1
            return -1;
        }
        return (n - maxsub);     //return n - lengthofsubarray to return the number of operations
    }
};