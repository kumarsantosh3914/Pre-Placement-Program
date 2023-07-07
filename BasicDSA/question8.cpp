vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // priority_queue<pair<int,int> > pq;
        // for(auto element:arr) {
        //     pq.push(make_pair(abs(x - element), element));
        //     if(pq.size() > k) {
        //         pq.pop();
        //     }
        // }
        // vector<int> ans;
        // while(!pq.empty()) {
        //     ans.push_back(pq.top().second);
        //     pq.pop();
        // }
        // sort(ans.begin(), ans.end());
        // return ans;
        vector<int> ans;
        int left = 0;
        int right = arr.size()-1;
        while(right - left >= k) {
            if(abs(arr[left] - x) > abs(arr[right] - x)) left++;
            else right--;
        }
        for(int i=left; i<=right; i++) {
            ans.push_back(arr[i]);
        }
        return ans;
    }