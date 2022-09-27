/**
 * @file solution690.cpp
 * @author your name (you@domain.com)
 * @brief 员工的重要性
 * @version 0.1
 * @date 2022-09-26
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

struct Employee {
    int id;
    int importance;
    vector<int> subordinates; //下属列表ID
};

int getImportance(vector<Employee *> employees, int id) {
    int ans = 0;

    // 建立映射关系
    unordered_map<int, Employee *> _map;
    for (Employee *employee : employees) {
        _map[employee->id] = employee;
    }
    queue<int> ids;
    ids.push(id);
    while (!ids.empty()) {
        int subId = ids.front();
        auto &newEmp = _map[subId];
        ans += newEmp->importance;
        for (auto &ssId : newEmp->subordinates) {
            ids.push(ssId);
        }
        ids.pop();
    }
    return ans;
}

int main() {
    return 0;
}