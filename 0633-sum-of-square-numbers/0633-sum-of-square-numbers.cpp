class Solution {
public:
    bool judgeSquareSum(int c) {
        long long left = 0;
        long long right = sqrt(c);

        while(left<=right){
            long long currentsum = left*left+right*right;
            if(currentsum == c){
                return true;
            }else if(currentsum<c){
                left++;
            }else{
                right--;
            }
        }
        return false;
    }
};