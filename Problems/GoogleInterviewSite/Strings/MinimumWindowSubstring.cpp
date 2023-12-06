class Solution {
public:
    unordered_map<char, int> qt, qt2;

    /**
        To solve it in  N + M, we need to use two pointers but the detail here
        is just to store the char quantity that we have in String T.

        Another thing is that if we use qt2.size() instead of Tot, qt2.size() will change
        every time that we do: qt2[s[b]] using a different s[b], then it's important to store the
        first qt2.size() in a variable like tot.

        Other than that, just keep doing the normal two pointer checking if the current window has
        all the characters

        Other good problems: A substring with concatenation of all words
        Minimum Size Subarray Sum
        Permutation in String

    */

    string minWindow(string s, string t) {
        int l = -1, r = -1;
        for (auto i : t) {
            qt2[i]++;
        }

        int a = 0, b = 0;
        int equal = 0;
        int formed = 0;
        int tot = qt2.size();
        while (a < s.size()) {
            while(b < s.size()) {
                qt[s[b]]++;

                if (qt[s[b]] == qt2[s[b]]) formed++;
                if (formed == tot) {
                    if (l == -1 || b - a < r - l) l = a, r = b;
                    qt[s[b]]--;
                    if (qt[s[b]] < qt2[s[b]]) formed--;
                    break;
                }

                b++;
            }

            qt[s[a]]--;
            if (qt[s[a]] == qt2[s[a]] - 1) formed--;
            a++;
        }
        
        if (l == -1) return "";
        
        return s.substr(l, r - l + 1);
    }
};