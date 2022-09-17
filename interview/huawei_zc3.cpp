#include <iostream>
#include <vector>
// #include <algorithm>

using namespace std;

void QuickSort(vector<int> &staff, int low, int high) { //快排
    if (low >= high) {                                  //若待排序序列只有一个元素，返回空
        return;
    }
    int i = low;          // i作为指针从左向右扫描
    int j = high;         // j作为指针从右向左扫描
    int key = staff[low]; //第一个数作为基准数
    while (i < j) {
        while (staff[j] >= key && i < j) { //从右边找小于基准数的元素 （此处由于j值可能会变，所以仍需判断i是否小于j）
            j--;                           //找不到则j减一
        }
        staff[i] = staff[j];               //找到则赋值
        while (staff[i] <= key && i < j) { //从左边找大于基准数的元素
            i++;                           //找不到则i加一
        }
        staff[j] = staff[i]; //找到则赋值
    }
    staff[i] = key; //当i和j相遇，将基准元素赋值到指针i处
    QuickSort(staff, low, i - 1);
    QuickSort(staff, i + 1, high);
}

int solve(vector<int> &staff, const int target) {
    int ans = 0;
    int left = 0;
    int right = staff.size() - 1;
    while (left < right) {
        if (staff[left] + staff[right] == target) {
            ans += 1;
            left++;
            right--;
        } else if (staff[left] + staff[right] < target) {
            left++;
        } else {
            right--;
        }
    }
    return ans;
}

int main() {
    int m; // 员工数量
    int s; //幸运数字个数
    vector<int> staff;
    vector<int> luck;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int _t;
        cin >> _t;
        staff.push_back(_t);
    }
    // sort(staff.begin(), staff.end());
    QuickSort(staff, 0, m - 1);
    cin >> s;
    for (int i = 0; i < s; i++) {
        int _t;
        cin >> _t;
        luck.push_back(_t);
    }
    int ans = 0;
    for (auto _n : luck) {
        ans += solve(staff, _n);
    }
    cout << ans << endl;
    return 0;
}