class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<bool> found(3, false);
        for (int i = 0; i<triplets.size(); i++){
            for (int j = 0; j<3; j++){
                if (triplets[i][j] == target[j] && triplets[i][(j+1)%3] <= target[(j+1)%3] && triplets[i][(j+2)%3] <= target[(j+2)%3]){
                    found[j] = true;
                }
                else{
                    continue;
                }
            }
        }
        return found[0] && found[1] && found[2];
    }
};
