// https://leetcode.com/problems/longest-repeating-character-replacement/description/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        int maxLen = 0;
        int maxf = 0;
         int hash[26];
        for (int i = 0; i < 26; ++i){
            hash[i] = 0;
        }

        while(r < s.size()){
            hash[s[r] - 'A']++;
            maxf = max(maxf, hash[s[r] - 'A']);
            while((r - l + 1) - maxf > k){
                hash[s[l] - 'A']--;
                maxf = 0;
                for(int i = 0; i < 25; ++i) maxf = max(maxf, hash[i]);
                l = l + 1;
            }
            if((r - l + 1) - maxf <= k) maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;

    }
};