#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int, int> cnt; // <key, value>
        int ans = 0;
        for (auto task : tasks) {
            if (cnt.find(task) != cnt.end()) cnt[task]++;
            else cnt.insert(pair<int, int>(task, 1));
        }
        for (auto p : cnt) {
            int task_cnt = p.second;
            if (task_cnt == 1) return -1;
            ans += (task_cnt+2) / 3;
        }
        return ans;
    }
};
