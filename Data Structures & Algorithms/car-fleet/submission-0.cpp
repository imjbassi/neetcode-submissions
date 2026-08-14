class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> cars;
        for (int i = 0; i < n; i++) {
            cars.push_back({position[i], speed[i]});
        }
        
        // Sort by position, descending — closest to target first
        sort(cars.begin(), cars.end(), greater<pair<int,int>>());
        
        stack<double> st;  // stores time-to-target for each fleet's "leader"
        
        for (auto& [pos, spd] : cars) {
            double time = (double)(target - pos) / spd;
            
            // If this car is slower (takes longer) than the fleet ahead,
            // it can never catch up — it becomes its own new fleet.
            if (st.empty() || time > st.top()) {
                st.push(time);
            }
            // else: this car catches up to the fleet ahead, merges in,
            // does NOT push — same fleet, no new fleet formed
        }
        
        return st.size();
    }
};