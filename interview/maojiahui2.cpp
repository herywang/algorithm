#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
class Solution {
public:
    std::string getStuID(std::string Student_Data) {
        std::stringstream ss(Student_Data);
        std::string tmpStr;
        std::string result;
        while (getline(ss, tmpStr, ' ')) {
            result += tmpStr.substr(0, 8);
            result.push_back(' ');
        }
        return result.substr(0, result.length() - 1);
    }
};

int main() {
    std::string str = "20200001张三 20200002李四 20200003王麻子";
    auto s = new Solution;
    std::cout << s->getStuID(str) << std::endl;
    delete s;
    return 0;
}