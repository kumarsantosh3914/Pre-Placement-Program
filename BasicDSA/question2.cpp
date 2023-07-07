int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        unordered_map<char, int> mp;
        int i = 0, j = 0;
        int maxi = INT_MIN;
        while(j < s.size()) {
            mp[s[j]]++;
            if(mp.size() == j - i + 1) {
                maxi = max(maxi, j - i + 1);
                j++;
            }
            else if(mp.size() < j - i + 1) {
                while(mp.size() < j - i + 1) {
                    mp[s[i]]--;
                    if(mp[s[i]] == 0) {
                        mp.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return maxi;
    }