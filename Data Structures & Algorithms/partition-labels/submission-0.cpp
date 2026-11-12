class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, int> letters;
        vector<int> res;
        for (char c: s){
            letters[c]++;
        }
        int index = 1; 
        set<char> current;
        for (char c: s){
            letters[c]--;
            current.insert(c);
            if (letters[c] == 0) current.erase(c);
            if (current.empty()) {         
                res.push_back(index);
                index = 0;
            }
            index++;
        }
        return res;
    }
};
