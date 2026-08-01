class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        
        vector<vector<int>> buckets(n + 1);
        for (const auto& p : count) {
            buckets[p.second].push_back(p.first);
        }
        
        vector<int> res;
        for (int freq = n; freq >= 1 && res.size() < k; freq--) {
            for (int num : buckets[freq]) {
                res.push_back(num);
                if (res.size() == k) break;
            }
        }
        return res;
    }
};