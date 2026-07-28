class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);

        // Count frequency of each character
        for (char c : s) {
            freq[c - 'a']++;
        }

        string left = "";
        char mid = '\0';

        // Build the left half in lexicographical order
        for (int i = 0; i < 26; i++) {
            left.append(freq[i] / 2, char('a' + i));

            if (freq[i] % 2 == 1) {
                mid = char('a' + i);
            }
        }

        // Right half is the reverse of left
        string right = left;
        reverse(right.begin(), right.end());

        // Construct the answer
        if (mid != '\0')
            return left + string(1, mid) + right;
        return left + right;
    }
};