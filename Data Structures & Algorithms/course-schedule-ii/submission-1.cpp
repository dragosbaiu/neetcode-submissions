class Solution {
    unordered_map <int, vector<int>> preMap;
    unordered_set<int> visiting;
    vector<int> order;
    unordered_set<int> done;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i<numCourses; i++){
            preMap[i] = {};
        }
        for (const auto& prereq: prerequisites){
            preMap[prereq[0]].push_back(prereq[1]);
        }
        for (int i = 0; i<numCourses; i++){
            if (!dfs(i)){
                return {};
            }
        }
        return order;
    }

    bool dfs(int course){
        if (done.count(course)) return true;
        if (visiting.count(course) != 0){
            return false;
        }

        visiting.insert(course);
        for (int pre: preMap[course]){
            if (!dfs(pre)){
                return false;
            }
        }
        order.push_back(course);
        done.insert(course);
        visiting.erase(course);
        return true;
    }
};
