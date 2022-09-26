#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    Solution() {
    }
    ~Solution() {
        cout << "调用了析构函数" << endl;
    }
    bool canAttendMeetings(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> v1, vector<int> v2) {
            return v1[0] - v2[0] < 0;
        });
        int last = -1;
        for (auto &vec : intervals) {
            if (vec[0] < last) {
                return false;
            }
            last = vec[1];
        }
        return true;
    }
};

int main() {
    shared_ptr<Solution> sp(new Solution);
    vector<vector<int>> intervals = {
        {0, 30}, {5, 10}, {15, 20}};
    cout << sp->canAttendMeetings(intervals) << endl;
    return 0;
}