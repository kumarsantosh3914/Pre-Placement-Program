class Solution {
private:
    struct cmp {
        bool operator() (pair<int, string> a, pair<int, string> b) {
            if(a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(auto it:words) mp[it]++;
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;
        for(auto it:mp) {
            pq.push({it.second, it.first});
        }
        
        vector<string> ans;
        while(k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};