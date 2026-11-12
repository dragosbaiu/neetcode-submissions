class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size()%groupSize != 0){
            return false;
        }
        map<int, int> cards;
        for (int i = 0; i< hand.size(); i++){
            cards[hand[i]]++;
        }
        for (int i = 0; i < hand.size()/groupSize; i++){
            int x = cards.begin()->first;
            for (int j = 0; j<groupSize; j++){
                if (cards[x+j] <=0){
                    return false;
                }
                if (--cards[x+j] == 0) {
                    cards.erase(x+j);
                }
            }
        }
        return true;
    }
};
