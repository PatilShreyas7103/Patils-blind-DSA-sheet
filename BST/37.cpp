// Q3. Longest Almost-Palindromic Substring (Exactly One Deletion)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int expand(string &s, int l, int r) {
        int n = s.size();
        bool deleted = false;

        while (l >= 0 && r < n) {

            if (s[l] == s[r]) {
                l--;
                r++;
            } 
            else {
                if (deleted) break;   // already deleted once
                deleted = true;

                // Try skipping left OR right
                int skipLeftL = l - 1, skipLeftR = r;
                int skipRightL = l, skipRightR = r + 1;

                int len1 = 0, len2 = 0;

                // simulate skip left
                int tl = skipLeftL, tr = skipLeftR;
                while (tl >= 0 && tr < n && s[tl] == s[tr]) {
                    tl--;
                    tr++;
                }
                len1 = tr - tl - 1;

                // simulate skip right
                tl = skipRightL;
                tr = skipRightR;
                while (tl >= 0 && tr < n && s[tl] == s[tr]) {
                    tl--;
                    tr++;
                }
                len2 = tr - tl - 1;

                return max(len1, len2);
            }
        }

        // If no mismatch occurred → no deletion used
        // But problem requires EXACTLY one deletion
        // So we must remove one char anyway
        return (r - l - 1 > 1) ? (r - l - 2) : 0;
    }

    int longestAlmostPalindromic(string s) {
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            // odd length
            ans = max(ans, expand(s, i, i));

            // even length
            ans = max(ans, expand(s, i, i + 1));
        }

        return ans;
    }
};