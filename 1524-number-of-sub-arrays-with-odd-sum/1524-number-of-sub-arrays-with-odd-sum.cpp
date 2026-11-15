class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int mod = 1e9+7;

        int ans = 0;
        int sum = 0;
        int odd = 0;
        int even = 1;
        int n = arr.size();
        for(int i = 0 ;i<n;i++){
            sum +=arr[i];

            if(sum%2==0){
                ans +=odd;
                even++;
            }else{
                ans +=even;
                odd++;
            }
            ans = ans%mod;
        }
        return ans;
    }
};