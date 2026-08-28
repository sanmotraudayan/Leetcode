class Solution {
public:

    string lexPalindromicPermutation(string s, string target) {

        int n = s.size();

        // Count characters
        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        // At most one odd frequency
        int odd = -1;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {

                if (odd != -1)
                    return "";

                odd = i;
            }
        }

        // Count characters for left half
        vector<int> halfCnt(26);

        for (int i = 0; i < 26; i++)
            halfCnt[i] = cnt[i] / 2;

        int halfLen = n / 2;

        string targetHalf = target.substr(0, halfLen);

        // Function to create palindrome
        auto makePalindrome = [&](string half) {

            string ans = half;

            // Middle character
            if (odd != -1)
                ans += char('a' + odd);

            // Reverse of left half
            string rev = half;
            reverse(rev.begin(), rev.end());

            ans += rev;

            return ans;
        };

        /*
            First check if target's left half
            can actually be formed.
        */

        vector<int> rem = halfCnt;

        bool possible = true;

        for (char c : targetHalf) {

            if (rem[c - 'a'] == 0) {
                possible = false;
                break;
            }

            rem[c - 'a']--;
        }

        // If target half is possible,
        // check whether its palindrome is already > target.
        if (possible) {

            string candidate = makePalindrome(targetHalf);

            if (candidate > target)
                return candidate;
        }

        /*
            Now find the smallest half
            strictly greater than targetHalf.
        */

        // Find how many characters of targetHalf
        // can be matched using our available characters.
        rem = halfCnt;

        int validPrefix = 0;

        for (int i = 0; i < halfLen; i++) {

            int c = targetHalf[i] - 'a';

            if (rem[c] == 0)
                break;

            rem[c]--;
            validPrefix++;
        }

        /*
            Try changing a position from right to left.

            We can change position `i` if:
            - everything before i can be matched
            - there is some character > targetHalf[i]
        */

        for (int i = min(validPrefix, halfLen - 1);
             i >= 0;
             i--) {

            // Recreate available characters
            vector<int> available = halfCnt;

            // Use characters of targetHalf before i
            bool prefixPossible = true;

            for (int j = 0; j < i; j++) {

                int c = targetHalf[j] - 'a';

                if (available[c] == 0) {
                    prefixPossible = false;
                    break;
                }

                available[c]--;
            }

            if (!prefixPossible)
                continue;

            // Current target character
            int current = targetHalf[i] - 'a';

            // Find smallest character greater than it
            for (int c = current + 1; c < 26; c++) {

                if (available[c] == 0)
                    continue;

                string newHalf = targetHalf.substr(0, i);

                newHalf += char('a' + c);

                available[c]--;

                // Fill remaining positions
                // with smallest possible characters
                for (int x = 0; x < 26; x++) {

                    while (available[x] > 0) {

                        newHalf += char('a' + x);

                        available[x]--;
                    }
                }

                return makePalindrome(newHalf);
            }
        }

        return "";
    }
};