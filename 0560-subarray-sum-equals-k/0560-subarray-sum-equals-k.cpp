class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        mpp[0]=1;
        int prefixsum = 0;int count = 0;
        for(int i = 0;i<nums.size();i++){
            prefixsum +=nums[i];
            int remove = prefixsum-k;
            count+=mpp[remove];
            mpp[prefixsum]++;
        }
        return count;
    }
};