class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> h;
        vector<int> count(26, 0);
        for (char c: tasks){
            count[c - 'A'] ++;
        }
        for (int i = 0; i<26; i++){
            if (count[i]!=0){
                h.push(count[i]);
            }
        }
        int time = 0;
        while(h.size() != 0){
            vector<int> temp;
            int taken = 0;

            for (int i = 0; i <= n; i++) {          
                if (h.empty()) break;               
                int c = h.top();
                h.pop();
                c--;                               
                if (c > 0) temp.push_back(c);       
                taken++;                            
            }
            for (int c : temp) h.push(c);

            time += h.empty() ? taken : n + 1;
        }
        return time;
    }
};
