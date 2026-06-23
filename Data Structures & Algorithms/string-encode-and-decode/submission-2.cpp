class Solution {
public:
    string encode(vector<string>& strs) {
        string s = "";
        for (auto &v : strs) {
            int k = v.size();
            string len = to_string(k);
            s += len + "#" + v; 
        }
        return s;
    }
    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0, n = s.size();
        while (i < n) {
            int j = i;
            while (s[j] != '#') j++;
            int len = stoi(s.substr(i, j - i)); 
            i = j + 1; 
            string word = s.substr(i, len);
            ans.push_back(word);
            i += len;
        }
        return ans;
    }
};
