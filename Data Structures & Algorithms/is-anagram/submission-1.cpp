class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <char, int> count;
        if (s.length() != t.length()) return false;
        
        for (char c : s) count[c]++;
        for (char c : t) count[c]--;
        
        for (auto& pair : count)
        {
            if (pair.second !=0) return false;
        }
        return true;
    }
};
