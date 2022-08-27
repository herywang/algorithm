//
// Created by wangheng on 2022/8/27.
//

#include <iostream>
#include <vector>

#define max(x, y) (x>y?x:y)
#define min(x, y) (x<y?x:y)

using namespace std;

struct RecSample {
    int N;//矩形个数
    vector<vector<int>> rec;//矩形信息
};


int solution(const RecSample *sample) {
    auto &recs = sample->rec;
    int ans = 0;
    int areaSize1 = 0, areaSize2 = 0;
    int repeatSize = 0;
    for (int i = 0; i < sample->N - 1; i++) {
        auto rec = recs[i];
        areaSize1 = (rec[2] - rec[0]) * (rec[3] - rec[1]);
        for (int j = i + 1; j < sample->N; j++) {
            auto _rec = recs[j];
            areaSize2 = (_rec[2] - _rec[0]) * (_rec[3] - _rec[1]);
            int n1, n2, m1, m2;
            //计算重叠区域左下角横坐标
            n1 = max(min(rec[0], rec[2]), min(_rec[0], _rec[2]));
            // 重叠区域左下角纵坐标
            m1 = max(min(rec[1], rec[3]), min(_rec[1], _rec[3]));
            n2 = min(max(rec[0], rec[2]), max(_rec[0], _rec[2]));
            m2 = min(max(rec[1], rec[3]), max(_rec[1], _rec[3]));
            if (n2 > n1 && m2 > m1) {
                repeatSize = (n2 - n1) * (m2 - m1);
                ans += areaSize1 + areaSize2 - repeatSize;
                break;
            }
        }
    }
    return ans;
}

int main(int argc, char *argv[]) {
    int T;
    cin >> T;
    if (T < 1) {
        return 0;
    }
    vector<RecSample *> samples;
    for (int i = 0; i < T; i++) {
        RecSample *s = new RecSample;
        cin >> s->N;
        for (int j = 0; j < s->N; j++) {
            vector<int> position(4, 0);
            for (int k = 0; k < 4; k++) {
                cin >> position[k];//输入点坐标
            }
            s->rec.emplace_back(position);
        }
        samples.emplace_back(s);
    }

    for (RecSample *_s: samples) {
        cout << solution(_s) << endl;
    }

    return 0;
}