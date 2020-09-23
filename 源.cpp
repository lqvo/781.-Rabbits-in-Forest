#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        if (answers.empty())return 0;
        if (answers.size() == 1)return answers[0] + 1;        
        sort(answers.begin(), answers.end());
        int onecolor = answers[0] + 1;
        int num = 1;
        int ans = onecolor;
        for (int i = 1; i < answers.size(); i++) {
            if (answers[i] == answers[i - 1]) {
                num++;
                if (num > onecolor)
                    ans += onecolor, num = 1;
            }
            else onecolor= answers[i] + 1,ans += onecolor, num = 1;
        }
        return ans;
    }
};
int main() {
    Solution sol;
    vector<int>nums = { 1,1,2 };
    cout << sol.numRabbits(nums);
    return 0;
}