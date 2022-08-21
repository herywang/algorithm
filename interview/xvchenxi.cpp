//
// Created by wangheng on 2022/8/20.
//

#include <iostream>
#include <vector>

using namespace std;

bool compare(pair<int,int> a, pair<int, int> b){
    return a.second>b.second;
}

int solution(vector<pair<int,int>> &samples, const int &m){
    int ans = 0;
    int count = 0;
    for(int i = samples.size()-1;i>=0;i--){
        while(true){
            auto &pair = samples[i];
            if(pair.first>0){
                ans += pair.second;
                count++;
                pair.first--;
                if(count==m){
                    return ans;
                }
            }else{
                break;
            }
        }
    }
    return ans;
}

int main() {
    int n, m;
    cin>>n>>m;
    vector<pair<int, int>> samples;
    for(int i = 0;i<n;i++){
        pair<int,int> p;
        cin>>p.first>>p.second;
        samples.push_back(p);
    }
    sort(samples.begin(), samples.end(), compare);

    cout<<solution(samples, m)<<endl;
    return 0;
}
