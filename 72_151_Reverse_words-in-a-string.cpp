// https://leetcode.com/problems/reverse-words-in-a-string/

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int i = 0;
        int n = s.length();

        while (i < n) {
            // Skip spaces
            while (i < n && s[i] == ' ') i++;

            if (i >= n) break;

            string temp = "";
            // Read a word
            while (i < n && s[i] != ' ') {
                temp += s[i];
                i++;
            }

            words.push_back(temp);
        }

        // Now reverse the collected words
        reverse(words.begin(), words.end());

        // Join with a single space
        string result = "";
        for (int j = 0; j < words.size(); j++) {
            result += words[j];
            if (j != words.size() - 1)
                result += " ";
        }

        return result;
    }
};
