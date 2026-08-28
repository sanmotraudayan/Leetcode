class Solution {
public:
    string lexGreaterPermutation(string s, string target) {

        int n = s.size();

        // Count characters in s
        vector<int> cnt(26, 0);

        for (char c : s) {
            cnt[c - 'a']++;
        }

        // remaining characters while matching target
        vector<int> rem = cnt;

        // Store the best position where we can make
        // the answer greater than target.
        int bestPos = -1;
        int bestChar = -1;
        vector<int> bestRem;

        for (int i = 0; i < n; i++) {

            int cur = target[i] - 'a';

            // Before consuming target[i], check if we can
            // put a character greater than target[i].
            for (int c = cur + 1; c < 26; c++) {

                if (rem[c] > 0) {

                    // Since we scan from left to right,
                    // overwrite previous candidate.
                    // The rightmost position is what we want.
                    bestPos = i;
                    bestChar = c;
                    bestRem = rem;

                    break;
                }
            }

            // Try to match target[i]
            if (rem[cur] == 0) {

                // target itself cannot be formed.
                // We need to make the first difference here.
                int greater = -1;

                for (int c = cur + 1; c < 26; c++) {
                    if (rem[c] > 0) {
                        greater = c;
                        break;
                    }
                }

                if (greater == -1) {

                    // No greater character here.
                    // Use the best earlier position.
                    break;
                }

                // Use the smallest greater character
                string ans = target.substr(0, i);

                ans += char('a' + greater);

                rem[greater]--;

                // Put remaining characters in ascending order
                for (int c = 0; c < 26; c++) {

                    while (rem[c] > 0) {
                        ans += char('a' + c);
                        rem[c]--;
                    }
                }

                return ans;
            }

            // Consume target[i]
            rem[cur]--;
        }

        // If we reached here, target itself can be formed.
        // We need the smallest permutation strictly greater than it.

        if (bestPos == -1) {
            return "";
        }

        // Reconstruct using the rightmost possible position
        string ans = target.substr(0, bestPos);

        ans += char('a' + bestChar);

        bestRem[bestChar]--;

        // Fill the rest with smallest characters
        for (int c = 0; c < 26; c++) {

            while (bestRem[c] > 0) {
                ans += char('a' + c);
                bestRem[c]--;
            }
        }

        return ans;
    }
};