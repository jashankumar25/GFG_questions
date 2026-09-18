class Solution {
public:
    int search(string &pat, string &txt) {
        int m = pat.size();
        int n = txt.size();

        if (m > n)
            return 0;

        unordered_map<char, int> need;
        unordered_map<char, int> window;

        for (char ch : pat)
            need[ch]++;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            window[txt[i]]++;

            if (i >= m) {
                char ch = txt[i - m];
                window[ch]--;

                if (window[ch] == 0)
                    window.erase(ch);
            }

            if (i >= m - 1) {
                if (window == need)
                    ans++;
            }
        }

        return ans;
    }
};