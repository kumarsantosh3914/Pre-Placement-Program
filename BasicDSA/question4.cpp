vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        // unordered_map<string, vector<string>> mp;
        unordered_map<string, vector<int>> mp;
        for(int i=0; i<strs.size(); i++) {
            auto s=strs[i];
            sort(s.begin(),s.end());
            mp[s].push_back(i);
        }
        for(auto a:mp) {
            vector<string> v = a.second;
            // for(auto it:a.second) v.push_back(strs[it]);
            ans.push_back(v);
        }
        return ans;
        // for(auto it:strs) {
        //     string temp = it;
        //     sort(it.begin(), it.end());
        //     mp[it].push_back(temp);
        // }
        // for(auto it : mp) {
        //     vector<string> v = it.second;
        //     ans.push_back(v);
        // }
        // return ans;
    }