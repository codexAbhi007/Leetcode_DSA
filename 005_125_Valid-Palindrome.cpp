#include <iostream>
#include <string>
#include <cctype>  // for isalnum and tolower

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            // Skip non-alphanumeric characters
            while (left < right && !isalnum(s[left])) left++;
            while (left < right && !isalnum(s[right])) right--;

            // Compare after converting both to lowercase
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};

int main() {
    Solution sol;

    string s1 = "A man, a plan, a canal: Panama";
    string s2 = "race a car";
    string s3 = " ";

    cout << boolalpha; 

    cout << "Is palindrome: \"" << s1 << "\" -> " << sol.isPalindrome(s1) << endl;
    cout << "Is palindrome: \"" << s2 << "\" -> " << sol.isPalindrome(s2) << endl;
    cout << "Is palindrome: \"" << s3 << "\" -> " << sol.isPalindrome(s3) << endl;

    return 0;
}
