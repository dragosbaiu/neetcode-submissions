class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>maxHeap(stones.begin(), stones.end());
        while(maxHeap.size() >=2){
            int x = maxHeap.top();
            maxHeap.pop();
            int y = maxHeap.top();
            maxHeap.pop();
            if (x == y){
                continue;
            }
            if (x > y){
                maxHeap.push(x - y);
            }
            else{
                maxHeap.push(y-x);
            }
        }
        if (maxHeap.size() == 1){
            return maxHeap.top();
        }
        else return 0;
    }
};
