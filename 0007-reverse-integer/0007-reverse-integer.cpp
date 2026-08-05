class Solution {
public:
    int reverse(int x) {
        int revnum =  0;
        while(x!=0){
            int ld = x%10;
             if (revnum > INT_MAX / 10 || (revnum == INT_MAX / 10 && ld > 7))
                return 0;

            if (revnum < INT_MIN / 10 || (revnum == INT_MIN / 10 && ld < -8))
                return 0;

            revnum = (revnum*10)+ld;
            x = x/10;
        }
        return revnum;
    }
};